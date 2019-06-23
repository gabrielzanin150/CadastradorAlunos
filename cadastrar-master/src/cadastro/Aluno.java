package cadastro;

import java.io.BufferedReader;   // importações para a parte grafica
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.JOptionPane;

public class Aluno {   				// criação da classe Aluno
	private String nome;
	private String notafinal;
	private String nascimento;
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	
	public String getNotafinal() {
		return notafinal;
	}
	public void setNotafinal(String notafinal) {
		this.notafinal = notafinal;
	}
	public String getNascimento() {
		return nascimento;
	}
	public void setNascimento(String nascimento) {
		this.nascimento = nascimento;
	}
	
	@Override
	public String toString() {
		return "Aluno [nome=" + nome + ", notafinal=" + notafinal + ", nascimento=" + nascimento + "]";
	}
	
	
	
	public Aluno() {
		super();
	}
	public String salvar()      // funcao para salvar em um arquivo txt os dados coletados
	{
		try
		{
			
			FileWriter fw = new FileWriter( "CadastroAlunos.txt", true);
			FileWriter fn = new FileWriter( "notas.txt", true);
			PrintWriter pw = new PrintWriter(fw);
			PrintWriter pn = new PrintWriter(fn);
			pw.println("Nome: " +this.nome);
			pw.println("Nascimento: "+this.nascimento+"\n");
			pn.println(this.notafinal);
			pw.println(this.notafinal+"\n");
			pw.flush();         // 
			fn.close();			// fecha para garantir que o arquivo seja salvo
			pw.close(); 		//
			fw.close();			//
		} catch (IOException ex)
		{
			Logger.getLogger(Aluno.class.getName()).log(Level.SEVERE, null, ex); //  tratamento de erro
		}
		return "Cadastro Realizado com Sucesso!"; // caso tudo ocorreu corretamente, salva e exibe a mensagem na tela
	}
	
}
