package cadastro;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Telacadastro extends JFrame {
	String nome;
	String notafinal;
	String nascimento;
	Aluno[] registro = new Aluno[10];
	int qtd_alunos = 0;

	private JPanel telatwo;
	private JTextField jTxtnome;
	private JTextField jTxtNascimento;
	private JTextField jTxtNota;
	private JLabel lblNome;
	private JLabel lblDataNascimento;
	private JLabel lblNotaFinal;
	private JButton btnVoltar;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Telacadastro frame = new Telacadastro();
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
	public Telacadastro() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		telatwo = new JPanel();
		telatwo.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(telatwo);
		telatwo.setLayout(null);
		
		jTxtnome = new JTextField();
		jTxtnome.setBounds(10, 48, 86, 20);
		telatwo.add(jTxtnome);
		jTxtnome.setColumns(10);
		
		jTxtNascimento = new JTextField();
		jTxtNascimento.setBounds(10, 105, 86, 20);
		telatwo.add(jTxtNascimento);
		jTxtNascimento.setColumns(10);
		
		jTxtNota = new JTextField();
		jTxtNota.setBounds(10, 161, 86, 20);
		telatwo.add(jTxtNota);
		jTxtNota.setColumns(10);
		
		lblNome = new JLabel("Nome");
		lblNome.setBounds(30, 23, 46, 14);
		telatwo.add(lblNome);
		
		lblDataNascimento = new JLabel("Data Nascimento");
		lblDataNascimento.setBounds(10, 80, 86, 14);
		telatwo.add(lblDataNascimento);
		
		lblNotaFinal = new JLabel("Nota Final");
		lblNotaFinal.setBounds(20, 136, 66, 14);
		telatwo.add(lblNotaFinal);
		
		JButton btnCadastrar = new JButton("Cadastrar");
		btnCadastrar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				/*nome = jTxtnome.getText();
				nascimento = jTxtNascimento.getText();
				notafinal = jTxtNota.getText();
				notafinal = notafinal.replace(",", "."); // troca vírgula por ponto
	     		Double notaDouble = Double.parseDouble(notafinal); // converte a nota de texto para decimal
				registro[qtd_alunos] = new Aluno(nome,notaDouble, nascimento);
				JOptionPane.showMessageDialog(null,"Aluno cadastrado com sucesso!");
				qtd_alunos++;
				dispose();
				*/
				
				Aluno aluno = new Aluno();
				aluno.setNome(jTxtnome.getText());
				aluno.setNascimento(jTxtNascimento.getText());
				aluno.setNotafinal(jTxtNota.getText());
				
			}
		});
		btnCadastrar.setBounds(238, 48, 130, 63);
		telatwo.add(btnCadastrar);
		
		btnVoltar = new JButton("Voltar");
		btnVoltar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
			}
		});
		btnVoltar.setBounds(257, 149, 89, 23);
		telatwo.add(btnVoltar);
	}
}
