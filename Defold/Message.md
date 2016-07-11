### Message 
- ex. msg.post(my_url, "my_message", {my_parameter = "my_value"})

- url sample
local my_url = msg.url("#my_component")
local my_url = msg.url("my_collection:/my_sub_collection/my_instance#my_component")
local my_url = msg.url("my_socket:")

//인풋 호출 요청
msg.post(".", "acquire_input_focus")