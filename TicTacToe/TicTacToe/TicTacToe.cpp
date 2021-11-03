/*
o o o
o o o  -> Esquema do tabuleiro, sendo repartido por btn (button): up (cima), low (baixo), left (esquerda), right (direita) e mid (meio).
o o o
*/


#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <string.h>

//Criando o tabuleiro 
int board[3][3], player, turnCounter;
//   ^Tabuleiro, ^        ^Quantas rodadas passaram
//               ^Vez de qual jogador
int winner; // Diz quem ganhou, player 1 ou 2

//Função que inicia o tabuleiro
void initBoard() {
	int i, j;

	player = 1;        // < Quem começa jogando
	turnCounter = 0;  // < Rodadas que se passaram no inicio.
	winner = 0;      // < No inicio ninguém ganhou ainda, por isso é igual a 0.

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			board[i][j] = 0;
		}
	}

}

//Função que verifica se alguém já ganhou
int checkBoard() {
	int i, j, p1, p2;
	//P1 é X e P2 é O

	//Verificando as linhas
	for (i = 0; i < 3; i++) {
		p1 = 0;
		p2 = 0;

		for (j = 0; j < 3; j++) {
			if (board[i][j] == 1)			 // Não usei chaves pois o if só precisa ler o primeiro argumento abaixo dele, logo, "dispensa" o uso de chaves
				p1++;						//  ^...
			else if (board[i][j] == 2)	   //  ^...
				p2++;					  //  ^...
		}

		if (p1 == 3)
			return 1;
		else if (p2 == 3)
			return 2;
	}

	//Verificando as colunas
	for (j = 0; j < 3; j++) {
		p1 = 0;
		p2 = 0;

		for (i = 0; i < 3; i++) {
			if (board[i][j] == 1)			 // Não usei chaves pois o if só precisa ler o primeiro argumento abaixo dele, logo, "dispensa" o uso de chaves
				p1++;						//  ^...
			else if (board[i][j] == 2)	   //  ^...
				p2++;					  //  ^...
		}

		if (p1 == 3)
			return 1;
		else if (p2 == 3)
			return 2;
	}

	//Checando a diagonal principal
	p1 = 0;
	p2 = 0;
	for (i = 0; i < 3; i++) {
		//Só preciso de um >for< aqui, pois sempre que o i for crescendo na linha, ele também cresce nas colunas, formando assim a diagonal
		if (board[i][i] == 1)
			p1++;
		else if (board[i][i] == 2)
			p2++;
	}

	if (p1 == 3)
		return 1;
	else if (p2 == 3)
		return 2;

	//Checando a diagonal secundária
	j = 2;
	p1 = 0;
	p2 = 0;
	for (i = 0; i < 3; i++) {
		if (board[i][j] == 1)
			p1++;						
		else if (board[i][j] == 2)
			p2++;
		j--; // < Sempre que o i for atualizado, ele verifica a coluna j, que vai se atualizando também, mas decrescendo.
	}

	if (p1 == 3)
		return 1;
	else if (p2 == 3)
		return 2;

	// Se ninguém ganhou
	return 0;
}

//Criando classes(Semelhante a structs em C puro, mas para fins gráficos, usarei o C++ por ser POO, o que torna as classes mais "poderosas", a lógica de programação estará em C) para a parte gráfica

//Classe do app
class TicTacToe : public wxApp {
public:
	//Sempre que o programa for chamado, esse trecho é "invocado"
	virtual bool OnInit();
};

//Classe da janela principal
class MainFrame : public wxFrame {
public:
	MainFrame();
protected:
	wxMenuBar* m_mainMenuBar; //  < O m_ vem antes para indicar que o código seguinte a ele é um membro da classe MainFrame.
	wxMenu* m_menuGame;      //  < Nesses  casos eu venho criando os menus da barra de menu's que criei acima.
	wxMenu* m_menuRules;    //  ^...
	wxMenu* m_menuHelp;    //  ^...

	wxButton* m_btnUpLeft;    // < Criando os botões superiores do tabuleiro.
	wxButton* m_btnUpMid;    // ^...
	wxButton* m_btnUpRight; // ^...

	wxButton* m_btnMidLeft;    // < Criando os botões do meio do tabuleiro.
	wxButton* m_btnMidMid;    // ^...
	wxButton* m_btnMidRight; // ^...

	wxButton* m_btnLowLeft;    // < Criando os botões inferiores do tabuleiro.
	wxButton* m_btnLowMid;    // ^...
	wxButton* m_btnLowRight; // ^...

	wxStatusBar* m_statusBar; // < Criando a parte de baixo da barra de status.

	char m_msgStatusBar[200];
private:
	//Criando os acontecimentos dos menus
	void OnNewGame(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnRules(wxCommandEvent& event);
	void OnScoreBoard(wxCommandEvent& event);
	void OnSupport(wxCommandEvent& event);

	void EnableGrid();
	void DisableGrid();
	void EndGame();

	//Criando os acontecimentos dos botões
	void OnBtnUpLeftClick(wxCommandEvent& event);
	void OnBtnUpMidClick(wxCommandEvent& event);
	void OnBtnUpRightClick(wxCommandEvent& event);

	void OnBtnMidLeftClick(wxCommandEvent& event);
	void OnBtnMidMidClick(wxCommandEvent& event);
	void OnBtnMidRightClick(wxCommandEvent& event);

	void OnBtnLowLeftClick(wxCommandEvent& event);
	void OnBtnLowMidClick(wxCommandEvent& event);
	void OnBtnLowRightClick(wxCommandEvent& event);

	//Chamando a função que diz na status bar de qual player é a vez
	//Entrada
	void OnBtnUpLeftEnterWindow(wxCommandEvent& event);
	void OnBtnUpMidEnterWindow(wxCommandEvent& event);
	void OnBtnUpRightEnterWindow(wxCommandEvent& event);

	void OnBtnMidLeftEnterWindow(wxCommandEvent& event);
	void OnBtnMidMidEnterWindow(wxCommandEvent& event);
	void OnBtnMidRightEnterWindow(wxCommandEvent& event);

	void OnBtnLowLeftEnterWindow(wxCommandEvent& event);
	void OnBtnLowMidEnterWindow(wxCommandEvent& event);
	void OnBtnLowRightEnterWindow(wxCommandEvent& event);
	//Saída
	void OnBtnUpLeftLeaveWindow(wxCommandEvent& event);
	void OnBtnUpMidLeaveWindow(wxCommandEvent& event);
	void OnBtnUpRightLeaveWindow(wxCommandEvent& event);

	void OnBtnMidLeftLeaveWindow(wxCommandEvent& event);
	void OnBtnMidMidLeaveWindow(wxCommandEvent& event);
	void OnBtnMidRightLeaveWindow(wxCommandEvent& event);

	void OnBtnLowLeftLeaveWindow(wxCommandEvent& event);
	void OnBtnLowMidLeaveWindow(wxCommandEvent& event);
	void OnBtnLowRightLeaveWindow(wxCommandEvent& event);
};

//Sempre que eu iniciar o app ele vai automaticamente criar esse método
bool TicTacToe::OnInit() {
	MainFrame* frame = new MainFrame();
	frame->Show();

	//Inicializando o tabuleiro sempre que clicar no new game ou iniciar o jogo:
	initBoard();

	return true;
}

//Criando o ID dos eventos que o wx não trás por padrão:
enum {
	ID_NewGame = 1
};

enum {
	ID_Rules = 2
};
enum {
	ID_ScoreBoard = 3
};
enum {
	ID_Support = 4
};

//Agora que as classes estão prontas, eu estou dizendo o que cada método faz:
MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, "TIC TAC TOE") {
	this->SetSizeHints(600, 600); // < Criando a janela de tamanho 600x600
	m_mainMenuBar = new wxMenuBar(0);
	m_menuGame = new wxMenu();
	m_menuRules = new wxMenu();
	m_menuHelp = new wxMenu();

	m_mainMenuBar->Append(m_menuGame, "Game");    // Fixando os menu's na barra de menu's.
	m_mainMenuBar->Append(m_menuRules, "Rules"); // ^...
	m_mainMenuBar->Append(m_menuHelp, "Help");  // ^...

	m_menuGame->Append(ID_NewGame, "&New Game\tCtrl+N", "Start a new match");			 // < Criando os submenu New Game
	m_menuGame->AppendSeparator();														// < Colocando uma linha separando os submenu's
	m_menuGame->Append(ID_ScoreBoard, "&Scoreboard\tCtrl+S", "Check the scoareboard"); // < Cria o submenu Scoreboard
	m_menuGame->AppendSeparator();													  // < Colocando uma linha separando os submenu's
	m_menuGame->Append(wxID_EXIT);													 // < Outro submenu dentro do menu game

	m_menuRules->Append(ID_Rules, "&Rules", "Game Rules"); // < Criando o submenu Rules

	m_menuHelp->Append(wxID_ABOUT);										// < Criando o submenu Help
	m_menuHelp->AppendSeparator();									   // < Colocando uma linha separadora entre as opções
	m_menuHelp->Append(ID_Support, "&Support", "Contact a support");  // < Criando o submenu support no menu Help
	
	wxFont font(48, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	this->SetMenuBar(m_mainMenuBar); // < "setando" a MenuBar

	wxGridSizer* gBoard = new wxGridSizer(3, 3, 0, 0);   // < Criando o grid que os botões estarão "anexados".
	gBoard->SetMinSize(500, 500);

	//Criando a parte que o usuário "enxerga" dos botões do tabuleiro
	m_btnUpLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnUpLeft->SetFont(font);
	gBoard->Add(m_btnUpLeft, 0, wxALL | wxEXPAND, 5);
	m_btnUpMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnUpMid->SetFont(font);
	gBoard->Add(m_btnUpMid, 0, wxALL | wxEXPAND, 5);
	m_btnUpRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnUpRight->SetFont(font);
	gBoard->Add(m_btnUpRight, 0, wxALL | wxEXPAND, 5);

	m_btnMidLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMidLeft->SetFont(font);
	gBoard->Add(m_btnMidLeft, 0, wxALL | wxEXPAND, 5);
	m_btnMidMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMidMid->SetFont(font);
	gBoard->Add(m_btnMidMid, 0, wxALL | wxEXPAND, 5);
	m_btnMidRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMidRight->SetFont(font);
	gBoard->Add(m_btnMidRight, 0, wxALL | wxEXPAND, 5);

	m_btnLowLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowLeft->SetFont(font);
	gBoard->Add(m_btnLowLeft, 0, wxALL | wxEXPAND, 5);
	m_btnLowMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowMid->SetFont(font);
	gBoard->Add(m_btnLowMid, 0, wxALL | wxEXPAND, 5);
	m_btnLowRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowRight->SetFont(font);
	gBoard->Add(m_btnLowRight, 0, wxALL | wxEXPAND, 5);

	this->SetSizer(gBoard);
	this->Layout();
	
	m_statusBar = this->CreateStatusBar(1, wxST_SIZEGRIP, wxID_ANY);

	this->Centre(wxBOTH);

	//Programando para o jogo só começar quando clicar no "new game"
	DisableGrid();
	SetStatusText("Go to new game to start a match.");

	//Associa os métodos aos eventos (Que será codado mais abaixo):
	Bind(wxEVT_MENU, &MainFrame::OnNewGame, this, ID_NewGame); 
	Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &MainFrame::OnRules, this, ID_Rules);
	Bind(wxEVT_MENU, &MainFrame::OnScoreBoard, this, ID_ScoreBoard);
	Bind(wxEVT_MENU, &MainFrame::OnSupport, this, ID_Support);

	//Associa os eventos dos botões (lá em baixo eu programo os botões):
	m_btnUpLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnUpLeftClick), NULL, this);
	m_btnUpMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnUpMidClick), NULL, this);
	m_btnUpRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnUpRightClick), NULL, this);

	m_btnMidLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidLeftClick), NULL, this);
	m_btnMidMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidMidClick), NULL, this);
	m_btnMidRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidRightClick), NULL, this);

	m_btnLowLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowLeftClick), NULL, this);
	m_btnLowMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowMidClick), NULL, this);
	m_btnLowRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowRightClick), NULL, this);

	m_btnUpLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpLeftEnterWindow), NULL, this);
	m_btnUpMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpMidEnterWindow), NULL, this);
	m_btnUpRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpRightEnterWindow), NULL, this);

	m_btnMidLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidLeftEnterWindow), NULL, this);
	m_btnMidMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidMidEnterWindow), NULL, this);
	m_btnMidRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidRightEnterWindow), NULL, this);

	m_btnLowLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowLeftEnterWindow), NULL, this);
	m_btnLowMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowMidEnterWindow), NULL, this);
	m_btnLowRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowRightEnterWindow), NULL, this);

	m_btnUpLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpLeftLeaveWindow), NULL, this);
	m_btnUpMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpMidLeaveWindow), NULL, this);
	m_btnUpRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpRightLeaveWindow), NULL, this);

	m_btnMidLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidLeftLeaveWindow), NULL, this);
	m_btnMidMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidMidLeaveWindow), NULL, this);
	m_btnMidRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidRightLeaveWindow), NULL, this);

	m_btnLowLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowLeftLeaveWindow), NULL, this);
	m_btnLowMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowMidLeaveWindow), NULL, this);
	m_btnLowRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowRightLeaveWindow), NULL, this);
}

wxIMPLEMENT_APP(TicTacToe); // < Chamando o jogo, essa é a função main do jogo.

//Eventos do tabuleiro:
void MainFrame::EnableGrid() {
	//Habilitando os botões para o clique
	m_btnUpLeft->Enable();
	m_btnUpMid->Enable();
	m_btnUpRight->Enable();
	m_btnMidLeft->Enable();
	m_btnMidMid->Enable();
	m_btnMidRight->Enable();
	m_btnLowLeft->Enable();
	m_btnLowMid->Enable();
	m_btnLowRight->Enable();

	//Deixando os botões "vazios"
	m_btnUpLeft->SetLabelText("");
	m_btnUpMid->SetLabelText("");
	m_btnUpRight->SetLabelText("");
	m_btnMidLeft->SetLabelText("");
	m_btnMidMid->SetLabelText("");
	m_btnMidRight->SetLabelText("");
	m_btnLowLeft->SetLabelText("");
	m_btnLowMid->SetLabelText("");
	m_btnLowRight->SetLabelText("");
}

void MainFrame::DisableGrid() {
	//Desabilitando os botões para o clique
	m_btnUpLeft->Disable();
	m_btnUpMid->Disable();
	m_btnUpRight->Disable();
	m_btnMidLeft->Disable();
	m_btnMidMid->Disable();
	m_btnMidRight->Disable();
	m_btnLowLeft->Disable();
	m_btnLowMid->Disable();
	m_btnLowRight->Disable();

	//Deixando os botões "vazios"
	m_btnUpLeft->SetLabelText("");
	m_btnUpMid->SetLabelText("");
	m_btnUpRight->SetLabelText("");
	m_btnMidLeft->SetLabelText("");
	m_btnMidMid->SetLabelText("");
	m_btnMidRight->SetLabelText("");
	m_btnLowLeft->SetLabelText("");
	m_btnLowMid->SetLabelText("");
	m_btnLowRight->SetLabelText("");
}

void MainFrame::EndGame() {
	char mensagem[200] = "";
	
	//Imprimindo quem ganhou a partida
	if (winner == 0) {
		strcpy(mensagem, "TIED MATCH");
	}
	else {
		if (winner == 1) {
			strcpy(mensagem, "X - Player 1 wins!");
		}
		else {
			if (winner == 2) {
				strcpy(mensagem, "O - Player 2 wins!");
			}
		}
	}

	//Concatenando a string para perguntar se o jogador deseja jogar novamente
	strcat(mensagem, " Play Again?");
	if (wxMessageBox(mensagem, "End of match!", wxYES_NO | wxICON_INFORMATION) == wxYES) {
		initBoard();				// Se o usuário desejar jogar novamente, entrará nesse if, e reiniciará o tabuleiro
		EnableGrid();			   // Deixando todos os botões clicáveis e limpando eles
	}
	else {
		Close(true);
	}
}


//Eventos que acontecem ao apertar os botões no menu:
void MainFrame::OnNewGame(wxCommandEvent& event) {
	EnableGrid();
	initBoard();
	//SetStatusText("It is player 1 turn");
}
void MainFrame::OnExit(wxCommandEvent& event){
	Close(true); // < Fecha a janela.
}
void MainFrame::OnAbout(wxCommandEvent& event){
	wxMessageBox("This is a TicTacToe example in C.\nCoded by Felipe Cabral, student at UERN, at this moment I'm taking the first semester of college of CS.", "About TicTacToe", wxOK | wxICON_INFORMATION);
}
void MainFrame::OnRules(wxCommandEvent& event) {
	wxMessageBox("TicTacToe is a game for two people, whose main objective is to form a line with 3 equal pieces, either horizontally, vertically or diagonally. If no participant completes the 3 pieces in sequence, the game is considered a draw.\nPlayer 1 - X\nPlayer 2 - O.", "Rules", wxOK | wxICON_INFORMATION);
}
void MainFrame::OnScoreBoard(wxCommandEvent& event) {
	wxMessageBox("This is a beta software, the scoreboard will be released soon.", "Scoreboard", wxOK | wxICON_INFORMATION);
}
void MainFrame::OnSupport(wxCommandEvent& event) {
	wxMessageBox("To contact a support, please send a e-mail to: felipecostacabral@hotmail.com", "Support", wxOK | wxICON_INFORMATION);
}


//Eventos que acontecem ao apertar os botões do tabuleiro:
void MainFrame::OnBtnUpLeftClick(wxCommandEvent& event) {
	//Desativando o botão e colocando o valor O ou X para ele
	if (m_btnUpLeft->IsEnabled()) {
		board[0][0] = player;
		m_btnUpLeft->Disable();
		if (player == 1) {
			m_btnUpLeft->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnUpLeft->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	winner = checkBoard();
	if (winner != 0 || turnCounter >= 9) {
		EndGame();
	}
}

void MainFrame::OnBtnUpMidClick(wxCommandEvent& event) {
	//Desativando o botão e colocando o valor O ou X para ele
	if (m_btnUpMid->IsEnabled()) {
		board[0][1] = player;
		m_btnUpMid->Disable();
		if (player == 1) {
			m_btnUpMid->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnUpMid->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	winner = checkBoard();
	if (winner != 0 || turnCounter >= 9) {
		EndGame();
	}
}

void MainFrame::OnBtnUpRightClick(wxCommandEvent& event) {
	//Desativando o botão e colocando o valor O ou X para ele
	if (m_btnUpRight->IsEnabled()) {
		board[0][2] = player;
		m_btnUpRight->Disable();
		if (player == 1) {
			m_btnUpRight->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnUpRight->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	winner = checkBoard();
	if (winner != 0 || turnCounter >= 9) {
		EndGame();
	}
}

void MainFrame::OnBtnMidLeftClick(wxCommandEvent& event) {
	//Desativando o botão e colocando o valor O ou X para ele
	if (m_btnMidLeft->IsEnabled()) {
		board[1][0] = player;
		m_btnMidLeft->Disable();
		if (player == 1) {
			m_btnMidLeft->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnMidLeft->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	winner = checkBoard();
	if (winner != 0 || turnCounter >= 9) {
		EndGame();
	}
}

void MainFrame::OnBtnMidMidClick(wxCommandEvent& event) {
	//Desativando o botão e colocando o valor O ou X para ele
	if (m_btnMidMid->IsEnabled()) {
		board[1][1] = player;
		m_btnMidMid->Disable();
		if (player == 1) {
			m_btnMidMid->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnMidMid->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	winner = checkBoard();
	if (winner != 0 || turnCounter >= 9) {
		EndGame();
	}
}

void MainFrame::OnBtnMidRightClick(wxCommandEvent& event) {
	//Desativando o botão e colocando o valor O ou X para ele
	if (m_btnMidRight->IsEnabled()) {
		board[1][2] = player;
		m_btnMidRight->Disable();
		if (player == 1) {
			m_btnMidRight->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnMidRight->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	winner = checkBoard();
	if (winner != 0 || turnCounter >= 9) {
		EndGame();
	}
}

void MainFrame::OnBtnLowLeftClick(wxCommandEvent& event) {
	//Desativando o botão e colocando o valor O ou X para ele
	if (m_btnLowLeft->IsEnabled()) {
		board[2][0] = player;
		m_btnLowLeft->Disable();
		if (player == 1) {
			m_btnLowLeft->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnLowLeft->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	winner = checkBoard();
	if (winner != 0 || turnCounter >= 9) {
		EndGame();
	}
}

void MainFrame::OnBtnLowMidClick(wxCommandEvent& event) {
	//Desativando o botão e colocando o valor O ou X para ele
	if (m_btnLowMid->IsEnabled()) {
		board[2][1] = player;
		m_btnLowMid->Disable();
		if (player == 1) {
			m_btnLowMid->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnLowMid->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	winner = checkBoard();
	if (winner != 0 || turnCounter >= 9) {
		EndGame();
	}
}

void MainFrame::OnBtnLowRightClick(wxCommandEvent& event) {
	//Desativando o botão e colocando o valor O ou X para ele
	if (m_btnLowRight->IsEnabled()) {
		board[2][2] = player;
		m_btnLowRight->Disable();
		if (player == 1) {
			m_btnLowRight->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnLowRight->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	winner = checkBoard();
	if (winner != 0 || turnCounter >= 9) {
		EndGame();
	}
}

void MainFrame::OnBtnUpLeftEnterWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnUpLeft->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnUpMidEnterWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnUpMid->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnUpRightEnterWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnUpRight->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnMidLeftEnterWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnMidLeft->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnMidMidEnterWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnMidMid->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnMidRightEnterWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnMidRight->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnLowLeftEnterWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnLowLeft->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnLowMidEnterWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnLowMid->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnLowRightEnterWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnLowRight->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnUpLeftLeaveWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnUpLeft->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnUpMidLeaveWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnUpMid->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnUpRightLeaveWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnUpRight->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnMidLeftLeaveWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnMidLeft->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnMidMidLeaveWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnMidMid->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnMidRightLeaveWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnMidRight->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnLowLeftLeaveWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnLowLeft->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnLowMidLeaveWindow(wxCommandEvent & event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.
	if (m_btnLowMid->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnLowRightLeaveWindow(wxCommandEvent& event) {
	//Aparece na barra de eventos lá em baixo de quem é o turno.3
	if (m_btnLowRight->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}