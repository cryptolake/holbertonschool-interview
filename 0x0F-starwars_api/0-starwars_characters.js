#!/usr/bin/node
const request = require('request');
const process = require('process');
const args = process.argv;

request(`https://swapi-api.hbtn.io/api/films/${args[2]}`, async function (error, response, body) {
  const characters = JSON.parse(body).characters;
  if (error != null) { console.log(error); }
  for (const url in characters) {
    await request(characters[url], async function (error, response, body) {
      if (error != null) { console.log(error); }
      const name = JSON.parse(body).name;
      await console.log(name);
    });
    await new Promise(resolve => setTimeout(resolve, 500));
  }
});
