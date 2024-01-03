#include <string>
class Response {
public:
  static const char* responseValid;
  static const char* responseInvalid;
  static const char* responseError;
  
};

const char* Response::responseValid = R"({"msg":"Credenciales validas"})";
const char* Response::responseInvalid = R"({"msg":"Credenciales inválidas"})";
const char* Response::responseError = R"({"msg":"Error en el servidor"})";
