package cadastro;

import javax.swing.JOptionPane;

public class cadastrar {
	public static void main (String []args)
	{
		String nome;
		String notafinal;
		String nascimento;
		Aluno[] registro = new Aluno[10];
		int qtd_alunos = 0;
		int opcao;
		
		do
		{
			 String bullet = JOptionPane.showInputDialog("Digite 1 para cadastrar ou 0 para sair");
		     opcao = Integer.parseInt(bullet);
		     
		     switch (opcao)
		     {
		     	case 1:
		     	{
		     		nome = JOptionPane.showInputDialog("Digite o nome do aluno:");
		     		nascimento = JOptionPane.showInputDialog("Digite a data de nascimento do aluno:");
		     		
		     		notafinal = JOptionPane.showInputDialog("Digite a nota do aluno");
		     		notafinal = notafinal.replace(",", "."); // troca vírgula por ponto
		     		Double notaDouble = Double.parseDouble(notafinal); // converte a nota de texto para decimal
		     		
		     		//registro[qtd_alunos] = new Aluno(nome,notaDouble, nascimento);
		     		qtd_alunos++;
		     	}
		     }
		    // registro[qtd_alunos].toString();
		     
		} while(opcao !=0 );
		
		int i;
		for(i=0; i<qtd_alunos; i++)
		{
			JOptionPane.showMessageDialog(null,registro[i].getNotafinal());
		}
		
		
		
		
	}
}
