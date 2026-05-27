cmake_minimum_required(VERSION 3.15)
project(launcher Java)
find_package(Java 1.7 REQUIRED COMPONENTS Development)

include(UseJava)
set(CMAKE_JAVA_JAR_ENTRY_POINT org.nitindyt.client.EntryPoint)
set(CMAKE_JAVA_COMPILE_FLAGS -target 7 -source 7)

set(SRC
    src/org/nitindyt/client/EntryPoint.java
    src/org/nitindyt/client/launcher/Launcher.java
    src/org/nitindyt/client/launcher/impl/AbstractLauncher.java
    src/org/nitindyt/client/launcher/impl/StandardLauncher.java
    src/org/nitindyt/client/exception/ParameterNotFoundException.java
    src/org/nitindyt/client/exception/ParseException.java
    src/org/nitindyt/client/utils/Parameters.java
    src/org/nitindyt/client/utils/ReflectionUtils.java
    src/org/nitindyt/client/utils/logging/Level.java
    src/org/nitindyt/client/utils/logging/Log.java
    src/org/nitindyt/client/legacy/LegacyProxy.java
)

set(LEGACY_SRC
    legacy/org/nitindyt/client/legacy/LegacyFrame.java
    legacy/org/nitindyt/client/legacy/LegacyLauncher.java
    legacy/org/nitindyt/client/legacy/fix/online/Handler.java
    legacy/org/nitindyt/client/legacy/fix/online/OnlineFixes.java
    legacy/org/nitindyt/client/legacy/fix/online/OnlineModeFix.java
    legacy/org/nitindyt/client/legacy/fix/online/SkinFix.java
    legacy/org/nitindyt/client/legacy/utils/Base64.java
    legacy/org/nitindyt/client/legacy/utils/api/MojangApi.java
    legacy/org/nitindyt/client/legacy/utils/api/Texture.java
    legacy/org/nitindyt/client/legacy/utils/json/JsonParseException.java
    legacy/org/nitindyt/client/legacy/utils/json/JsonParser.java
    legacy/org/nitindyt/client/legacy/utils/url/ByteArrayUrlConnection.java
    legacy/org/nitindyt/client/legacy/utils/url/UrlUtils.java
    legacy/org/nitindyt/client/legacy/LegacyProxy.java
    legacy/net/minecraft/Launcher.java
)

add_jar(NewLaunch ${SRC})
add_jar(NewLaunchLegacy ${LEGACY_SRC} INCLUDE_JARS NewLaunch)
install_jar(NewLaunch "${JARS_DEST_DIR}")
install_jar(NewLaunchLegacy "${JARS_DEST_DIR}")
