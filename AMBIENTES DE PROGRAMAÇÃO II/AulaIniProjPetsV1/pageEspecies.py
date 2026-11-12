import cherrypy
from classes.especie import Especie

class PaginaEspecie():
    topo = open("html/cabecalho.html").read()
    rodape = open("html/rodape.html").read()
    
    @cherrypy.expose()
    def index(self):
        return self.montaFormulario()
    
    def montaFormulario(self, pId=0, pDescricao=''):
        html = self.topo
        
        html += f'''
                <h2>Especies de Animais</h2>
                <form name="FormCadastro" action="gravarEspecie" method="post">
                <p>
                <input type="hidden" id="txtId" name="txtId" value="{pId}"/>
                
                <label for="txtDescr">Descricao da Especie</label>
                <br/>
                <input type="text" id="txtDesc" name="txtDesc" value="{pDescricao}" size="30" maxlength="30" required="required"/>
                <br/><br/>
                </p>
                
                <br/>
                <input type="submit" id="btnGravar" name="btnGravar" value="Gravar"/>
                </form>
            '''
        
        html += self.montaTabela()
        html += self.rodape
        
        return html
    
    def montaTabela(self):
        
        html = '''
            <table class="alinha">
                <tr>
                    <th>Código</th>
                    <th>Descrição</th>
                    <th>Ações</th>
                </tr>
        '''
        
        objEspecie = Especie()
        
        dados = objEspecie.obterEspecies()
        
        for esp in dados:
            html += f'''
                <tr>
                    <td> {esp["esp_id"]} </td>
                    <td> {esp["esp_descricao"]} </td>
                    <td>
                        <a href="excluirEspecie?idEsp={esp["esp_id"]}">[excluir]</a>
                    </td>
                </tr>
            '''
            
        html += '''
            </table><br><br><br>
        '''
        
        return html

    @cherrypy.expose()
    def gravarEspecie(self, txtId, txtDesc, btnGravar):
        if (len(txtDesc)>0): # Confere se tem alguma informação para gravar
            objespcie = Especie()
            objespcie.set_descricao(txtDesc)

            txtId = int(txtId)

            if txtId == 0:
                retorno = objespcie.gravar()
            else:
                print("Alterar...")

            if retorno > 0:
                return f'''
                    <script>
                    alert("A espécie {txtDesc} foi gravada com !SUCESSO!")
                    </script>
                '''
            else:
                return f'''
                    <h2>Erro ao gravar a espécie {txtDesc}</h2>
                    <a href="/"> voltar</a>
                '''
        else:
            return'''
                    <h2> A descrição da espécie deve ser informada</h2>
                    <a href+"/"> voltar</a>
                '''
    @cherrypy.expose()
    def excluirEspecie(self, idEsp):
        objEspecie = Especie()
        objEspecie.set_id(idEsp)

        retorno = objEspecie.excluir()

        if retorno>0:
            raise cherrypy.HTTPRedirect('/rotaespecie')
        else:
            return f'''
                    <h2>Não foi possivel excluir a espécie {idEsp}</h2>
                    <a href="/"> voltar</a>    
                '''