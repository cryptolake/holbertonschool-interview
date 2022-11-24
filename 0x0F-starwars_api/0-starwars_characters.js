#!/usr/bin/node
const request = require('request');
const process = require('process');
const args = process.argv;

request(`https://swapi-api.hbtn.io/api/films/${args[2]}`, function (error, response, body) {
  const characters = JSON.parse(body).characters;
  if (error != null)
    console.log(error);
  for (const url in characters) {
    request(characters[url], function (error, response, body) {
      if (error != null)
        console.log(error);
      console.log(JSON.parse(body).name);
    });
  }
});
