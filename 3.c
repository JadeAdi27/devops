Create one html/jsp file in “src/main/webapp/index.html” and add

-----------------------------------------------
“src/main/webapp/WEB-INF/web.xml” file.
Step-4: Include below plugin in “web.xml”

<plugin>
  <groupId>org.apache.maven.plugins</groupId>
  <artifactId>maven-war-plugin</artifactId>
  <configuration>
    <webXml>src/main/webapp/WEB-INF/web.xml</webXml> <!-- This file defines which page to start -->
  </configuration>
</plugin>

  //dockerfile

FROM tomcat:9.0
RUN rm -rf /usr/local/tomcat/webapps/*
COPY /target/sample.war /usr/local/tomcat/webapps/ROOT.war
EXPOSE 8080

-----------------
  docker build -t sample-app .
  docker run -d -p 8095(give unused port number ):8080 sample-app;
  http://localhost:8095


docker ps
docker stop <container_id>
docker rm <container_id>
  -----------------------------------------------------------
  -----------------------------------------------------------
  -----------------------------------------------------------
    //app1.py
from flask import Flask
app = Flask(__name__)
@app.route('/')
def hello():
    return "Hello from App 1!"
if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
  -------
    //dockerfile
FROM python:3.12-slim
WORKDIR /app
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt
COPY app.py .
EXPOSE 5000
CMD ["python", "app.py"]
  ---------
    //requirements
  flask==3.0.0
----------------------------------------------
    //app2.py
import requests
response = requests.get("http://app1:5000/")
print("Response from App 1:", response.text)
  //requirements.txt
  ------------------
  requests==2.31.0
  //dockerfile
  -------------------
FROM python:3.12-slim
WORKDIR /app
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt
COPY app.py .
CMD ["python", "app.py"]
----------------------------------------------
  --------------------------------------------
  //docker-compose.yml
  version: '3.9'
services:
  app1:
    build: ./app1
    networks:
      - app-network
    ports:
      - "5000:5000"
  app2:
    build: ./app2
    networks:
      - app-network
    depends_on:
      - app1
networks:
  app-network:
    driver: bridge
  --------------------------------
  docker-compose build
docker-compose up
docker-compose logs app2
    

    
