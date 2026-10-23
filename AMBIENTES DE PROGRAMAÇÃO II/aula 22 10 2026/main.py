import cherrypy
import os

class MyProject(object):
    @cherrypy.expose
    def index(self):
        with open("static/paginas/main.html", "r", encoding='utf-8') as f:
            return f.read()
    
    @cherrypy.expose
    def nome(self, sobrenome = ""):
        cherrypy.session['sobrenome'] = sobrenome
        return f"nome: joão \n Sobrenome: {sobrenome}"

    @cherrypy.expose
    def display(self):
        return cherrypy.session['sobrenome']

conf = {
    '/' : {
        'tools.sessions.on' : True,
        'tools.staticdir.root' : os.path.abspath(os.getcwd())
    },
    '/static' :{
        'tools.staticdir.on':True,
        'tools.staticdir.dir' : 'static'
    }
}


cherrypy.quickstart(MyProject(),'/',conf)