FROM nginx:latest

WORKDIR /part4

COPY nginx/nginx.conf /etc/nginx/

COPY /scripts/ /part4/

RUN bash install.sh && gcc -o hello_server hello-world.c -lfcgi

CMD ["sh", "-c", "spawn-fcgi -p 8080 ./hello_server && nginx -g 'daemon off;'"]
