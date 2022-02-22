idf_component_register(SRCS "proto-cpp/addressbook.pb.cc"
                    INCLUDE_DIRS 
                    	proto-cpp
                    PRIV_REQUIRES 
                  		protobuf
                  	LDFRAGMENTS
            			"linker.lf"
                    	)
