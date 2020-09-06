RED='\033[31m'
NC='\033[0m'
SEP="echo ================================================================================"

$SEP
# echo INSTALLING DOCKER && brew install docker docker-machine
# echo INSTALLING VIRTUALBOX && brew cask install virtualbox
# echo INSTALLING MINIKUBE && brew install minikube
$SEP

minikube start \
    --network-plugin=cni \
    --enable-default-cni \
    --container-runtime=docker \
    --bootstrapper=kubeadm

    /usr/bin/sudo -E -- /usr/bin/env LOGNAME=artygo USER=artygo USERNAME=artygo /usr/sbin/installer -pkg /usr/local/Caskroom/virtualbox/6.1.10,138449/VirtualBox.pkg -target / -applyChoiceChangesXML /var/folders/ww/vrcpkv2d5y18m7y0fts9hc780000gn/T/choices20200628-23071-ur1drb.xml
