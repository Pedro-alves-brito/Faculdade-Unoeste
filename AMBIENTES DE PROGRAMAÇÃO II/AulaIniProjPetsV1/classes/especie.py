from classes.banco import Banco

class Especie():
    def __init__(self):
        self.__id = 0
        self.__descricao = ''
        
        self.__banco = Banco()
    
    def set_id(self,pId):
        if pId > 0:
            self.__id = pId
    
    def set_descricao(self,pDesc):
        if len(pDesc) > 0:
            self.__descricao = pDesc
    
    def get_id(self):
        return self.__id
    
    def get_descricao(self):
        return self.__descricao
    
    def obterEspecies(self):
        sql = '''
            SELECT
                *
            FROM especies
            ORDER BY esp_descricao
        '''
        
        return self.__banco.executarSelect(sql)
    
    def obterEspecie(self, idEsp):
        
        if idEsp > 0:
            self.set_id = idEsp
            sql = f'''
                SELECT
                    *
                FROM especies
                WHERE esp_id = {idEsp}
            '''
        else:
            sql = f'''
                SELECT
                    *
                FROM especies
                ORDER BY esp_descricao
            '''
        
        return self.__banco.executarSelect(sql)

    def gravar(self):
        sql = f'INSERT INTO especies(esp_descricao) VALUES("{self.get_descricao()}")'

        return self.__banco.executarInsertUpdateDelete(sql)

    def excluir(self):
        sql = f'DELET FROM especies WHERE esp_id = {self.get_id()}'

        return self.__banco.executarInsertUpdateDelete(sql)

    