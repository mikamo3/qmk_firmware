FROM qmkfm/base_container

ARG USER_UID=1000
ARG USER_GID=$USER_UID
ARG USER_NAME=dev

RUN apt-get update && apt-get install --no-install-recommends -y \
  sudo \
  && rm -rf /var/lib/apt/lists/*
RUN useradd -u ${USER_UID} -G sudo -m -s /bin/bash ${USER_NAME} && \
  echo "${USER_NAME} ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers