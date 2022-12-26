#!/usr/bin/python3
"""Get hot posts from reddit sub."""
import requests


def count_words(subreddit, word_list, after='', hot_list=None):
    """Get posts of sub."""
    word_list = [item.lower() for item in word_list]
    if hot_list is None:
        hot_list = {item: 0 for item in word_list}

    if after is None:
        for word in sorted(hot_list, key=lambda x: (-hot_list[x], x)):
            if hot_list[word] != 0:
                print("{}: {}".format(word, hot_list[word]))
        return None

    headers = {'User-Agent': "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7)"}
    url = 'https://www.reddit.com'
    res = requests.get('{}/r/{}/hot.json?after={}'
                       .format(url, subreddit, after), headers=headers,
                       allow_redirects=False)

    if res.status_code == 200:
        rj = res.json()
        if rj.get('data') is None:
            return None
        for post in rj['data']['children']:
            title = post['data']['title'].lower().split(' ')
            for word in word_list:
                hot_list[word] += title.count(word)

        return count_words(subreddit, word_list, rj['data']['after'], hot_list)
    return None
