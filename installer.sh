function installDependencies() {
    echo 'Instalando dependencias' >&2
    sudo apt-get install libsdl2-dev
    sudo apt-get install libsdl2-image-dev
    sudo apt-get install libsdl2-ttf-dev
    sudo apt-get install libsdl2-mixer-dev
    sudo apt-get install libgtk-3-dev
    sudo apt-get install libgtkmm-3.0-dev
    sudo apt-get install libboost-dev
    sudo apt-get install libyaml-cpp-dev
    sudo apt-get install build-essential
    sudo apt-get install qtcreator
    sudo apt-get install qt5-default
    sudo apt-get install qt5-doc
    sudo apt-get install qt5-doc-html qtbase5-doc-html
    sudo apt-get install qtbase5-examples
    sudo apt-get install cmake
}

function startCompiling() {
    cmake CMakeLists.txt
}

function compileServer() {
    echo 'Instalando ServerDune2000' >&2
    make ServerDune2000
    sudo mv ServerDune2000 /usr/local/games
    ln -s /usr/local/games/ServerDune2000 ServerDune2000
}

function compileClient() {
    echo 'Instalando ClientDune2000' >&2
    make ClientDune2000
    sudo mv ClientDune2000 /usr/local/games
    ln -s /usr/local/games/ClientDune2000 ClientDune2000
}

function compileEditor() {
    echo 'Instalando Dune2000Editor' >&2
    make DuneEditorDeMapas
    sudo mv DuneEditorDeMapas /usr/local/games
    ln -s /usr/local/games/DuneEditorDeMapas DuneEditorDeMapas
}

function clean() {
    rm -rf CMakeFiles
    rm -f CMakeCache.txt cmake_install.cmake Makefile
}

function moveConfigAndResources() {
    if [ ! -d /usr/local/share/Dune2000 ]; then
      sudo mkdir /usr/local/share/Dune2000
    fi
    if [ ! -d /usr/local/etc/Dune2000 ]; then
      sudo mkdir /usr/local/etc/Dune2000
  	fi
}

case $1 in
-i)
    installDependencies
    exit 0
  ;;
-s)
    startCompiling
    compileServer
    moveConfigAndResources
    clean
    exit 0
  ;;
-c)
    startCompiling
    compileClient
    moveConfigAndResources
    clean
    exit 0
  ;;
-e)
    startCompiling
    compileEditor
    moveConfigAndResources
    clean
    exit 0
  ;;
--help | -h | \?)
    echo "Help:
    Sin opciones instala el servidor, cliente y editor y configura los archivos. NO SE INSTALARAN DEPENDENCIAS.
    -i para instalar dependencias
    -c para instalar el cliente
    -s para instalar el servidor
    -e para instalar el editor
    -conf para configurar el ambiente" >&2
    exit 0
    ;;
esac

startCompiling
compileServer
compileEditor
compileClient
moveConfigAndResources
clean
exit 0