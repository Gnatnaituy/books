from socketserver import BaseRequestHandler, ThreadingTCPServer

class EchoHanlder(BaseRequestHandler):

	def handle(self):
		print('Got connection from ', self.client_address)
		while True:
			msg = self.request.recv(8092)
			if not msg:
				break
			self.request.send(msg)


if __name__ == '__main__':
	serv = ThreadingTCPServer(('', 20010), EchoHanlder)
	serv.serve_forever()
