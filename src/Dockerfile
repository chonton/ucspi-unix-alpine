ARG ALPINE_VERSION

FROM repocache.nonprod.ppops.net/docker-remote/alpine:${ALPINE_VERSION} as work

RUN apk add --no-cache make gcc build-base
COPY * build/
RUN cd build && make

FROM repocache.nonprod.ppops.net/docker-remote/alpine:${ALPINE_VERSION}

COPY --from=work /build/unixcat /usr/bin/
COPY --from=work /build/ucspiunix /usr/bin/
RUN ln -s ./ucspiunix /usr/bin/unixserver; ln -s ./ucspiunix /usr/bin/unixclient
