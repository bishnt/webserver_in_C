# 🚀 Web Server in C

A lightweight, high-performance HTTP web server built from scratch in C. This project demonstrates low-level socket programming and HTTP protocol implementation without external dependencies.

## ✨ Features

- **Pure C Implementation** - No external libraries or frameworks
- **HTTP/1.1 Support** - Handles GET requests with proper HTTP responses
- **Static File Serving** - Serves files from the `public/` directory
- **RESTful API Endpoint** - Built-in JSON API at `/api/random`
- **Custom Routing System** - Modular request routing and handling
- **Error Handling** - Proper 404 and 405 HTTP error responses
- **Concurrent Connections** - Handles multiple client connections

## 🏗️ Architecture

The server is built with a modular architecture:

```
├── server.c       # Main server setup and socket handling
├── http.c         # HTTP request parsing and handling
├── router.c       # Request routing and response logic
├── file_server.c  # Static file serving functionality
└── public/        # Static files directory
```

## 🚀 Quick Start

### Prerequisites

- GCC compiler
- Linux/Unix environment
- Make utility

### Building

```bash
# Clone the repository
git clone <your-repo-url>
cd webserver_in_C

# Build the server
make

# Clean build files (optional)
make clean
```

### Running

```bash
# Start the server
./server

# The server will start on port 8000
# Visit http://localhost:8000 in your browser
```

## 📡 API Endpoints

| Method | Endpoint | Description | Response |
|--------|----------|-------------|----------|
| `GET` | `/` | Root endpoint | Plain text greeting |
| `GET` | `/api/random` | JSON API endpoint | JSON response |
| `GET` | `/*` | Static files | Serves from `public/` directory |

### Example Responses

**Root Endpoint (`/`):**
```
HTTP/1.1 200 OK
Content-Type: text/plain

Hello World!
```

**API Endpoint (`/api/random`):**
```json
HTTP/1.1 200 OK
Content-Type: application/json

{"message":"Hi there"}
```

**Static Files:**
- Place files in the `public/` directory
- Access via `http://localhost:8000/filename.ext`
- Includes a sample `index.html` with a personal profile page

## 🛠️ Configuration

### Port Configuration
The server runs on port **8000** by default. To change the port, modify this line in `server.c`:

```c
sockaddress.port = htons(8000); // Change 8000 to your desired port
```

### API Endpoints
Add new API endpoints by modifying the `API_PATH` constant in `router.c`:

```c
#define API_PATH "/api/random" // Change this path
```

### Static File Directory
Static files are served from the `public/` directory. The path is configured in `file_server.c`:

```c
snprintf(full_path, sizeof(full_path), "./public%s", path);
```

## 📁 Project Structure

```
webserver_in_C/
│
├── 📄 server.c           # Main server and socket setup
├── 📄 http.c/.h          # HTTP request parsing
├── 📄 router.c/.h        # Request routing logic
├── 📄 file_server.c/.h   # Static file serving
├── 📄 Makefile           # Build configuration
├── 📄 README.md          # This file
│
├── 📁 public/            # Static files directory
│   └── 📄 index.html     # Sample HTML page
│
├── 📁 .vscode/           # VS Code configuration
│   ├── 📄 c_cpp_properties.json
│   └── 📄 settings.json
│
└── 📄 .gitignore         # Git ignore rules
```

## 🔧 Development

### Adding New Routes

1. **Define the handler function** in `router.c`:
```c
void handle_new_route(int client_fd) {
    const char* response = 
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "\r\n"
        "Your response here";
    write(client_fd, response, strlen(response));
}
```

2. **Add the route** in the `route_request()` function:
```c
else if(strcmp(req->path, "/new-route") == 0) {
    handle_new_route(client_fd);
}
```

3. **Declare the function** in `router.h`:
```c
void handle_new_route(int client_fd);
```

### Supported HTTP Methods

Currently supports:
- ✅ `GET` requests
- ❌ `POST`, `PUT`, `DELETE` (returns 405 Method Not Allowed)

## 🐛 Error Handling

The server handles common HTTP errors:

- **404 Not Found** - For missing static files
- **405 Method Not Allowed** - For unsupported HTTP methods

## 🔒 Security Considerations

⚠️ **This is a learning project and not production-ready**

Current limitations:
- No input validation or sanitization
- No protection against directory traversal attacks
- No authentication or authorization
- No HTTPS support
- Limited error handling

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

## 🙋‍♂️ Author

**Snuggbun** - *A person trying to be someone*

---

⭐ **Star this repository if you found it helpful!**

*Built with ❤️ and lots of C programming*
