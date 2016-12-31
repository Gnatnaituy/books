from werkzeug.wrappers import Request, Response


# The environ contains all incoming information
# The start_response function can be used to indicate the start of the response
def applocation(environ, start_response):
	request = Request(environ)
	text = 'Hello %s!' % request.args.get('name', 'World')
	response = Response(text, mimetype='text/plain')
	return response(environ, start_response)
