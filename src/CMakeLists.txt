add_executable(learn_sip
        main.cpp
)
target_link_libraries(learn_sip PRIVATE
        pthread
        spdlog
)
