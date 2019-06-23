package cadastro;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Font;
import java.awt.SystemColor;

public class NotasVisualizacao extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() { // criação da janela de exibição
			public void run() {
				try {
					NotasVisualizacao frame = new NotasVisualizacao();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public NotasVisualizacao() {
		
		int vetor[] = new int[10]; // vetor resposável pelo armazenamento da quantidade de ocorrencia das notas lidas do arquivo
		int i=0;
		for(i=0; i<9; i++) // zera todos os campos do vetor, ou seja, nao existem ocorrencias de inicio
			vetor[i]=0;
		try{
			
			String nome;
			nome = ("notas.txt");  // lógica de leitura de um arquivo
			
			BufferedReader br = new BufferedReader(new FileReader(nome));
			while(br.ready()){
				
				String linha = br.readLine();
				
				linha = linha.replace(",", "."); // troca vírgula por ponto
	     		Double nota = Double.parseDouble(linha); // converte a nota de texto para decimal
	     		double nota1 = nota;
	     			if(nota1>=0.0 && nota<1.0) // na leitura das notas no arquivo, aqui verifica em qual intervalo se encaixa e acrescenta 1 na posição da nota em questão
	     				vetor[0]++;
	     			
	     			if(nota1>=1.0 && nota<2.0)
	     				vetor[1]++;
	     			
	     			if(nota1>=2.0 && nota<3.0)
	     				vetor[2]++;
	     			
	     			if(nota1>=3.0 && nota<4.0)
	     				vetor[3]++;
	     			
	     			if(nota1>=4.0 && nota<5.0)
	     				vetor[4]++;
	     			
	     			if(nota1>=5.0 && nota<6.0)
	     				vetor[5]++;
	     			
	     			if(nota1>=6.0 && nota<7.0)
	     				vetor[6]++;
	     			
	     			if(nota1>=7.0 && nota<8.0)
	     				vetor[7]++;
	     			
	     			if(nota1>=8.0 && nota<=9.0)
	     				vetor[8]++;
	     			
	     			if(nota1>=9.0 && nota<=10.0)
	     				vetor[9]++;
			}
			
			br.close(); // fecha o arquivo e trata erros
		}catch(IOException ioe){
			ioe.printStackTrace();
			
			
		}
		//////////////////// declaração de nomes ou campos da tela de exibição ///////////////////////////
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBackground(SystemColor.activeCaption);
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNotasDe = new JLabel("Notas de 9 a 10:");
		lblNotasDe.setBounds(10, 11, 109, 14);
		contentPane.add(lblNotasDe);
		
		JLabel lblNotasDe_1 = new JLabel("Notas de 8 a 9:");
		lblNotasDe_1.setBounds(10, 36, 109, 14);
		contentPane.add(lblNotasDe_1);
		
		JLabel lblNotasDe_2 = new JLabel("Notas de 7 a 8:");
		lblNotasDe_2.setBounds(10, 61, 109, 14);
		contentPane.add(lblNotasDe_2);
		
		JLabel lblNotasDe_3 = new JLabel("Notas de 6 a 7:");
		lblNotasDe_3.setBounds(10, 86, 109, 14);
		contentPane.add(lblNotasDe_3);
		
		JLabel lblNotasDe_4 = new JLabel("Notas de 5 a 6:");
		lblNotasDe_4.setBounds(10, 111, 109, 14);
		contentPane.add(lblNotasDe_4);
		
		JLabel lblNotasDe_5 = new JLabel("Notas de 4 a 5:");
		lblNotasDe_5.setBounds(10, 136, 109, 14);
		contentPane.add(lblNotasDe_5);
		
		JLabel lblNotasDe_6 = new JLabel("Notas de 3 a 4:");
		lblNotasDe_6.setBounds(10, 161, 109, 14);
		contentPane.add(lblNotasDe_6);
		
		JLabel lblNotasDe_7 = new JLabel("Notas de 2 a 3:");
		lblNotasDe_7.setBounds(10, 186, 109, 14);
		contentPane.add(lblNotasDe_7);
		
		JLabel lblNotasDe_8 = new JLabel("Notas de 1 a 2:");
		lblNotasDe_8.setBounds(10, 211, 109, 14);
		contentPane.add(lblNotasDe_8);
		
		JLabel lblNotasDe_9 = new JLabel("Notas de 0 a 1:");
		lblNotasDe_9.setBounds(10, 236, 109, 14);
		contentPane.add(lblNotasDe_9);
		
		JLabel lb10 = new JLabel("New label");
		lb10.setBounds(129, 11, 46, 14);
		lb10.setForeground(Color.blue);
		contentPane.add(lb10);
		String num10  = Integer.toString(vetor[9]);
		lb10.setText(num10);
		
		JLabel lb9 = new JLabel("New label");
		lb9.setBounds(129, 36, 46, 14);
		lb9.setForeground(Color.blue);
		contentPane.add(lb9);
		String num9  = Integer.toString(vetor[8]);
		lb9.setText(num9);
		
		JLabel lb8 = new JLabel("New label");
		lb8.setBounds(129, 61, 46, 14);
		lb8.setForeground(Color.blue);
		contentPane.add(lb8);
		String num8  = Integer.toString(vetor[7]);
		lb8.setText(num8);
		
		JLabel lb7 = new JLabel("New label");
		lb7.setBounds(129, 86, 46, 14);
		lb7.setForeground(Color.blue);
		contentPane.add(lb7);
		String num7  = Integer.toString(vetor[6]);
		lb7.setText(num7);
		
		JLabel lb6 = new JLabel("New label");
		lb6.setBounds(129, 111, 46, 14);
		lb6.setForeground(Color.blue);
		contentPane.add(lb6);
		String num6  = Integer.toString(vetor[5]);
		lb6.setText(num6);
		
		JLabel lb5 = new JLabel("New label");
		lb5.setBounds(129, 136, 46, 14);
		lb5.setForeground(Color.red);
		contentPane.add(lb5);
		String num5  = Integer.toString(vetor[4]);
		lb5.setText(num5);
		
		JLabel lb4 = new JLabel("New label");
		lb4.setBounds(129, 161, 46, 14);
		lb4.setForeground(Color.red);
		contentPane.add(lb4);
		String num4  = Integer.toString(vetor[3]);
		lb4.setText(num4);
		
		JLabel lb3 = new JLabel("New label");
		lb3.setBounds(129, 186, 46, 14);
		lb3.setForeground(Color.red);
		contentPane.add(lb3);
		String num3  = Integer.toString(vetor[2]);
		lb3.setText(num3);
		
		JLabel lb2 = new JLabel("New label");
		lb2.setBounds(129, 211, 46, 14);
		lb2.setForeground(Color.red);
		contentPane.add(lb2);
		String num2  = Integer.toString(vetor[1]);
		lb2.setText(num2);
		
		JLabel lb1 = new JLabel("New label");
		lb1.setBounds(129, 236, 46, 14);
		lb1.setForeground(Color.red);
		contentPane.add(lb1);
		String num1  = Integer.toString(vetor[0]);
		lb1.setText(num1);
		
		JButton btnVoltar = new JButton("Voltar");
		btnVoltar.setBackground(SystemColor.menu);
		btnVoltar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
			}
		});
		btnVoltar.setBounds(335, 232, 89, 23);
		contentPane.add(btnVoltar);
		
		JLabel lblCadastrador = new JLabel("Cadastrador");
		lblCadastrador.setFont(new Font("Yu Gothic Medium", Font.BOLD | Font.ITALIC, 20));
		lblCadastrador.setBounds(227, 79, 130, 23);
		lblCadastrador.setForeground(Color.DARK_GRAY);
		contentPane.add(lblCadastrador);
		
		JLabel lblDe = new JLabel("de");
		lblDe.setFont(new Font("Yu Gothic Medium", Font.BOLD | Font.ITALIC, 20));
		lblDe.setBounds(268, 115, 46, 23);
		lblDe.setForeground(Color.DARK_GRAY);
		contentPane.add(lblDe);
		
		JLabel lblAlunos = new JLabel("Alunos");
		lblAlunos.setFont(new Font("Yu Gothic Medium", Font.BOLD | Font.ITALIC, 20));
		lblAlunos.setBounds(246, 140, 96, 51);
		lblAlunos.setForeground(Color.DARK_GRAY);
		contentPane.add(lblAlunos);
	}
}
