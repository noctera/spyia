add_library(spyia STATIC
    secretFile.cpp
	files/fileTypeBase.cpp
	files/image.cpp
	encryption/aes.cpp
	encryption/none.cpp
	encryption/encryptionBase.cpp
	steganography/stegAlgoBase.cpp
)

find_package( OpenCV REQUIRED )

target_include_directories(spyia PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
target_link_libraries(spyia PUBLIC fmt::fmt cryptopp)
target_link_libraries(spyia PUBLIC 
	opencv_core
	opencv_imgproc
	opencv_imgcodecs
)

set_target_warnings(spyia)

set_target_outputs(spyia)