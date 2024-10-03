FROM nginx:latest

WORKDIR /part4

COPY nginx/nginx.conf /etc/nginx/

COPY /scripts/ /part4/

RUN bash install.sh && gcc -o hello_server hello-world.c -lfcgi \
	&& chmod g-s /usr/bin/chage /usr/bin/expiry /usr/sbin/unix_chkpwd \
	&& chmod u-s /usr/bin/mount /usr/bin/passwd /usr/bin/umount \
	 /usr/bin/gpasswd /usr/bin/su /usr/bin/chfn /usr/bin/newgrp /usr/bin/chsh \
	&& groupadd nginxgroup \
	&& useradd -M -s /bin/bash -g nginxgroup nginxuser \
	&& mkdir -p /var/run /var/cache/nginx /var/log/nginx \
	&& touch /var/run/nginx.pid \
	&& chown -R nginxuser:nginxgroup /var/run /var/cache/nginx /var/log/nginx /var/run/nginx.pid \
	 /etc/nginx/nginx.conf

USER nginxuser

CMD ["sh", "-c", "spawn-fcgi -p 8080 ./hello_server && nginx -g 'daemon off;'"]

HEALTHCHECK --interval=1m --timeout=5s \
	CMD curl -f http://localhost || exit 1
