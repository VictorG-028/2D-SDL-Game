#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <time.h>
#include <math.h>
// #include <windows.h>
// #include <dos.h>
// #include <io.h>


//criação das variaveis de imagens e janelas
SDL_Window* janela = NULL;
SDL_Surface* superficiePrincipal = NULL;
SDL_Surface* background = NULL;
SDL_Renderer* window_Renderer = NULL;
SDL_Texture* gTexture = NULL;
SDL_Texture* detetive2 = NULL;
SDL_Texture* detetive3 = NULL;
SDL_Texture* detetive4 = NULL;
SDL_Texture* detetive5 = NULL;
SDL_Texture* detetive6 = NULL;
SDL_Texture* detetive7 = NULL;
SDL_Texture* detetive8 = NULL;
SDL_Texture* detetive9 = NULL;
SDL_Texture* detetive10 = NULL;
SDL_Texture* detetive11 = NULL;
SDL_Texture* detetive12 = NULL;
SDL_Texture* detetive13 = NULL;
SDL_Texture* texto_do_cenario_3 = NULL;
SDL_Texture* pista1 = NULL;
SDL_Texture* pista2 = NULL;
SDL_Texture* pista3 = NULL;
SDL_Texture* pista4 = NULL;
SDL_Texture* caixa = NULL;
SDL_Texture* carta = NULL;
SDL_Texture* bauAberto = NULL;
SDL_Texture* miniChave1 = NULL;
SDL_Texture* miniChave2 = NULL;
SDL_Texture* miniChave3 = NULL;
SDL_Texture* miniChave4 = NULL;
SDL_Texture* miniBau = NULL;

// Chama todas as funções init necessárias
void init()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Init(SDL_INIT_AUDIO);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 23000);
}


// Chama todas as funções quit necessárias
void quit()
{
	IMG_Quit();
	SDL_Quit();

	TTF_Quit();
	Mix_CloseAudio();
}



// ------------------------------------------------------------------------------------- //


// Função que carrega uma surface e cria uma textura dessa surface
SDL_Texture* load_texture(const char* image_Path, SDL_Renderer* window_Renderer)
{
	SDL_Texture* new_Texture = NULL;
	SDL_Surface* loaded_Surface = NULL;

	loaded_Surface = IMG_Load(image_Path);

	new_Texture = SDL_CreateTextureFromSurface(window_Renderer, loaded_Surface);

	SDL_FreeSurface(loaded_Surface);

	return new_Texture;
}


// Função que permite alterar as características de um retângulo
void alterar_retangulo(SDL_Rect* rect, int x, int y, int w, int h)
{
	(*rect).x += x;
	(*rect).y += y;
	(*rect).w += w;
	(*rect).h += h;
}

// Função que coloca o fundo preto
void coloca_fundo_preto(SDL_Renderer* window_Renderer)
{
	SDL_Texture* fundo_Preto_Texture = load_texture("imagens/fundo preto.png", window_Renderer);

	SDL_RenderCopy(window_Renderer, fundo_Preto_Texture, NULL, NULL);

	SDL_DestroyTexture(fundo_Preto_Texture);
	fundo_Preto_Texture = NULL;
}

// Função que salva o jogo
void save_game(int cenarios_Completos, int dificuldade, bool som_Ligado)
{
	FILE* arquivo = fopen("imagens/save.txt", "w");

	fprintf(arquivo,"%i %i %i", cenarios_Completos, dificuldade, som_Ligado);

	fclose(arquivo);
}


// Função que da load no jogo
void carregar_jogo(int* cenarios_Completos, int* dificuldade, bool* som_Ligado)
{
	FILE* arquivo = fopen("imagens/save.txt", "r");

	const int som = (int)(*som_Ligado);

	fscanf(arquivo, "%i %i %i", cenarios_Completos, dificuldade, &som );

	if (som)
	{
		*som_Ligado = true;
	}
	else
	{
		*som_Ligado = false;
	}

	printf("cenarios completos = %i \n", *cenarios_Completos);
	printf("som ligado = %i \n", *som_Ligado);

	fclose(arquivo);
}

// Ativa\Desativa a musica do jogo
void musica(Mix_Music* musica_jogo, int contador)
{
	if (contador == 1)
	{
		Mix_PlayMusic(musica_jogo, -1);
	}
	if (contador == 0)
	{
		Mix_HaltMusic();
	}
}

bool loadImage(SDL_Renderer* window_Renderer)
{
	bool sucesso = true;
	
	//adiciona a imagem a superficie inteira
	gTexture = load_texture("imagens/pokemon room.png", window_Renderer);

	//adiciona imagens individuais
	detetive2 = load_texture("imagens/detetive2.png", window_Renderer);
	detetive3 = load_texture("imagens/detetive3.png", window_Renderer);
	detetive4 = load_texture("imagens/detetive4.png", window_Renderer);
	detetive5 = load_texture("imagens/detetive5.png", window_Renderer);
	detetive6 = load_texture("imagens/detetive6.png", window_Renderer);
	detetive7 = load_texture("imagens/detetive7.png", window_Renderer);
	detetive8 = load_texture("imagens/detetive8.png", window_Renderer);
	detetive9 = load_texture("imagens/detetive9.png", window_Renderer);
	detetive10 = load_texture("imagens/detetive10.png", window_Renderer);
	detetive11 = load_texture("imagens/detetive11.png", window_Renderer);
	detetive12 = load_texture("imagens/detetive12.png", window_Renderer);
	detetive13 = load_texture("imagens/detetive13.png", window_Renderer);
	pista1 = load_texture("imagens/chatbox1.png", window_Renderer);
	pista2 = load_texture("imagens/chatbox2.png", window_Renderer);
	pista3 = load_texture("imagens/chatbox3.png", window_Renderer);
	pista4 = load_texture("imagens/chatbox4.png", window_Renderer);
	caixa = load_texture("imagens/chatboxbau.png", window_Renderer);
	carta = load_texture("imagens/chatboxcarta.png", window_Renderer);
	bauAberto = load_texture("imagens/chatboxbauaberto.png", window_Renderer);
	miniChave1 = load_texture("imagens/chave.png", window_Renderer);
	miniChave2 = load_texture("imagens/chave.png", window_Renderer);
	miniChave3 = load_texture("imagens/chave.png", window_Renderer);
	miniChave4 = load_texture("imagens/chave.png", window_Renderer);
	miniBau = load_texture("imagens/bau.png", window_Renderer);

	if (gTexture == NULL)
	{
		printf("imagem não localizada %s! SDL Error: %s\n", "imagens/background.png", SDL_GetError());
		sucesso = false;
	}
	return sucesso;
}

// ---------------------- //

//Função de atualizar o movimento de detetives
void mov_detetive(int* contador, const char* caminho, SDL_Texture* texture, SDL_Rect detetive, SDL_Renderer* window_Renderer)
{
	*contador += 1;

	texture = load_texture(caminho, window_Renderer);

	SDL_RenderCopy(window_Renderer, texture, NULL, &detetive);

	SDL_DestroyTexture(texture);
}

//carrega e executa o som dos passos
void som_passos(Mix_Chunk* Passos_1, Mix_Chunk* Passos_2, Mix_Chunk* Passos_3, int* contagem)
{
	if (*contagem == 0)
	{
		Mix_PlayChannel(-1, Passos_1, 0);
		*contagem = 1;
	}
	else if (*contagem == 1)
	{
		Mix_PlayChannel(-1, Passos_2, 0);
		*contagem = 2;
	}
	else if (*contagem == 2)
	{
		Mix_PlayChannel(-1, Passos_3, 0);
		*contagem = 0;
	}

}

//Mantem o detetive na tela mesmo após pressionar uma tecla que não seja de movimentação
void manter_detetive(int* contador1, int* contador2, int* contador3, int* contador4, int* tecla, SDL_Rect* rect, SDL_Texture* textura, const char* caminho, SDL_Renderer* window_Renderer)
{
	textura = load_texture(caminho, window_Renderer);
	*contador1 = 1;
	*contador2 = 1;
	*contador3 = 1;
	*contador4 = 1;

	if (*tecla == 1)
	{
		rect->y += 10;
	}
	else if (*tecla == 2)
	{
		rect->x += 10;
	}
	else if (*tecla == 3)
	{
		rect->y -= 10;
	}
	else if (*tecla == 4)
	{
		rect->x -= 10;
	}

	*tecla = 0;

	SDL_RenderCopy(window_Renderer, textura, NULL, rect);

	SDL_DestroyTexture(textura);
}

SDL_Texture* criar_texto(const char* frase, TTF_Font* fonte, SDL_Renderer* window_Renderer)
{
	SDL_Surface* criadora_texto = NULL;

	criadora_texto = TTF_RenderText_Solid(fonte, frase, { 0,0,0 });

	SDL_Texture* textura_texto = SDL_CreateTextureFromSurface(window_Renderer, criadora_texto);
	SDL_FreeSurface(criadora_texto);

	return textura_texto;
}

void texto(int flag, bool habilitar, SDL_Texture* textura, SDL_Rect mostrar_texto, TTF_Font* fonte, SDL_Renderer* window_Renderer)
{
	const char* frase = "Hm!";

	if (flag == 0 && habilitar == true)
	{
		frase = "Onde será que estao os fragmentos das paginas?";
	}
	else if (flag == 0 && habilitar == false)
	{
		frase = "O que será que podemos encontrar por aqui?";
	}
	else if (flag == 1 && habilitar == true)
	{
		frase = "Encontrei a primeira!";
	}
	else if (flag == 1 && habilitar == false)
	{
		frase = "Mas o que será isso?";
	}
	else if (flag == 2 && habilitar == true)
	{
		frase = "Mais uma, sinto que estou me aproximando de uma pista";
	}
	else if (flag == 2 && habilitar == false)
	{
		frase = "Intrigante, aparentemente existem vários desses pápeis espalhados por aqui!";
	}
	else if (flag == 3 && habilitar == true)
	{
		frase = "Falta pouco!";
	}
	else if (flag == 3 && habilitar == false)
	{
		frase = "Já é a terceira, espero que isso me leve a algum lugar!";
	}
	else if (flag == 4 && habilitar == true)
	{
		frase = "Consegui, essa com certeza é a última!";
	}
	else if (flag == 4 && habilitar == false)
	{
		frase = "Acho que foram todos, mas o que é isso?";
	}
	else if (flag == 5 && habilitar == true)
	{
		frase = "Agora tudo faz sentido, são pedaços da página rasgada!";
	}
	else if (flag == 6)
	{
		frase = "Pressione E para interagir";
	}
	else if (flag == 7)
	{
		frase = "Uma página com um cravo?! isso é familiar.";
	}

	textura = criar_texto(frase, fonte, window_Renderer);
	SDL_RenderCopy(window_Renderer, textura, NULL, &mostrar_texto);
	SDL_RenderPresent(window_Renderer);
}

// -------------------------------------------------------------------------------------- //


void creditos(SDL_Renderer* window_Renderer)
{
	SDL_Texture* creditos_Texture = load_texture("imagens/creditos.png", window_Renderer);

	SDL_RenderCopy(window_Renderer, creditos_Texture, NULL, NULL);
	
	// ------------------------------- //

	SDL_Event event;
	bool creditos = true;
	
	while (creditos)
	{
		SDL_RenderPresent(window_Renderer);

		while (SDL_PollEvent(&event) != 0)
		{
			//Evento: Fechar janela | Evento: qualquer tecla pressionada | Evento: qualquer botçao do mause pressionado
			if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN)
			{
				creditos = false;
			}
		} // Fim do loop de eventos
	
	} // Fim do while(creditos)

	// Finalização dos créditos
	SDL_DestroyTexture(creditos_Texture);

	creditos_Texture = NULL;

} // Fim da função de créditos


void controle(SDL_Renderer* window_Renderer)
{
	SDL_Event event;
	bool controle = true;

	SDL_Texture* controle_Texture = load_texture("imagens/controles.png", window_Renderer);
	SDL_RenderCopy(window_Renderer, controle_Texture, NULL, NULL);

	while (controle)
	{
		SDL_RenderPresent(window_Renderer);

		while (SDL_PollEvent(&event) != 0)
		{
			//Evento: Fechar janela | Evento: qualquer tecla pressionada | Evento: qualquer botçao do mause pressionado
			if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN)
			{
				controle = false;
			}
		} // Fim do loop de eventos
	}// Fim do while(controle)

	// Finalização dos créditos
	SDL_DestroyTexture(controle_Texture);

	controle_Texture = NULL;

} // Fim da função de controle


void settings(SDL_Renderer* window_Renderer, SDL_Surface* window_Surface, SDL_Texture* seta_Menu_Texture, SDL_Rect seta_Clip[], SDL_Texture* background_Texture, bool* som_Ligado)
{
	SDL_Texture* botoes_Texture = load_texture("imagens/botoes settings.png", window_Renderer);

	SDL_Rect botoes_Apagados_Rect;
	botoes_Apagados_Rect.x = (window_Surface->w) / 4;
	botoes_Apagados_Rect.y = (window_Surface->h) / 2;
	botoes_Apagados_Rect.w = 80 * 7;
	botoes_Apagados_Rect.h = 48 * 7;

	SDL_Rect botoes_Apagados_Clip;
	botoes_Apagados_Clip.x = 0;
	botoes_Apagados_Clip.y = 0;
	botoes_Apagados_Clip.w = 80;
	botoes_Apagados_Clip.h = 48;

	SDL_Rect botao_Acesso_Rect;
	botao_Acesso_Rect.x = (window_Surface->w) / 4;
	botao_Acesso_Rect.y = (window_Surface->h) / 2;
	botao_Acesso_Rect.w = 80 * 7;
	botao_Acesso_Rect.h = 16 * 7;

	SDL_Rect botao_Acesso_Clip;
	botao_Acesso_Clip.x = 0;
	botao_Acesso_Clip.y = 48;
	botao_Acesso_Clip.w = 80;
	botao_Acesso_Clip.h = 16;

	// ------------------------------- //

	SDL_Texture* botao_Voltar_Texture = load_texture("imagens/botao voltar.png", window_Renderer);

	SDL_Rect botao_Voltar_Rect;
	botao_Voltar_Rect.x = 0;
	botao_Voltar_Rect.y = 0;
	botao_Voltar_Rect.h = 16 * 5;
	botao_Voltar_Rect.w = 48 * 5;

	// ------------------------------- //

	SDL_Rect seta_Rect;
	seta_Rect.x = (window_Surface->w) / 4 - 16 * 5;
	seta_Rect.y = (window_Surface->h) / 2;
	seta_Rect.w = 16 * 5;
	seta_Rect.h = 16 * 5;

	// ------------------------------- //

	// Descobre qual textura do som:ON/OFF deve aparecer
	if (!(*som_Ligado))
	{
		alterar_retangulo(&botoes_Apagados_Clip, +(5 * 16), 0, 0, 0);
		alterar_retangulo(&botao_Acesso_Clip, +(5 * 16), 0, 0, 0);
	}

	// ------------------------------- //

	int seta_Posicao = 0;
	int seta_Sprite = 1;

	SDL_Event event;
	bool settings = true;

	while (settings)
	{
		SDL_RenderPresent(window_Renderer);

		while (SDL_PollEvent(&event) != 0) // Enquanto existir evento o loop continua
		{
			// Evento: fechar main_Window
			if (event.type == SDL_QUIT)
			{
				settings = false;
			}
			// Evento: tecla pressionada
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_DOWN:
					if (seta_Posicao + 1 <= 2)
					{
						seta_Rect.y += 16 * 7;
						seta_Posicao += 1;

						alterar_retangulo(&botao_Acesso_Rect, 0, +(16 * 7), 0, 0);
						alterar_retangulo(&botao_Acesso_Clip, 0, +(16), 0, 0);
					}
					break;

				case SDLK_UP:
					if (seta_Posicao - 1 >= 0)
					{
						seta_Rect.y -= 16 * 7;
						seta_Posicao -= 1;

						alterar_retangulo(&botao_Acesso_Rect, 0, -(16 * 7), 0, 0);
						alterar_retangulo(&botao_Acesso_Clip, 0, -(16), 0, 0);
					}
					break;

				case SDLK_s:
					if (seta_Posicao + 1 <= 2)
					{
						seta_Rect.y += 120;
						seta_Posicao += 1;

						alterar_retangulo(&botao_Acesso_Rect, 0, +(16 * 7), 0, 0);
						alterar_retangulo(&botao_Acesso_Clip, 0, +(16), 0, 0);
					}
					break;

				case SDLK_w:
					if (seta_Posicao - 1 >= 0)
					{
						seta_Rect.y -= 120;
						seta_Posicao -= 1;

						alterar_retangulo(&botao_Acesso_Rect, 0, -(16 * 7), 0, 0);
						alterar_retangulo(&botao_Acesso_Clip, 0, -(16), 0, 0);
					}
					break;

				case SDLK_RETURN:
					switch (seta_Posicao)
					{
					case 0:
						if (*som_Ligado)
						{
							alterar_retangulo(&botoes_Apagados_Clip, +(5 * 16), 0, 0, 0);
							alterar_retangulo(&botao_Acesso_Clip, +(5 * 16), 0, 0, 0);

							(*som_Ligado) = false;
						}
						else
						{
							alterar_retangulo(&botoes_Apagados_Clip, -(5 * 16), 0, 0, 0);
							alterar_retangulo(&botao_Acesso_Clip, -(5 * 16), 0, 0, 0);

							(*som_Ligado) = true;
						}

						break;

					case 1:
						creditos(window_Renderer);
						break;

					case 2:
						controle(window_Renderer);
						break;
					}

					break;

				case SDLK_SPACE:
					switch (seta_Posicao)
					{
					case 0:
						if (*som_Ligado)
						{
							alterar_retangulo(&botoes_Apagados_Clip, +(5 * 16), 0, 0, 0);
							alterar_retangulo(&botao_Acesso_Clip, +(5 * 16), 0, 0, 0);

							(*som_Ligado) = false;
						}
						else
						{
							alterar_retangulo(&botoes_Apagados_Clip, -(5 * 16), 0, 0, 0);
							alterar_retangulo(&botao_Acesso_Clip, -(5 * 16), 0, 0, 0);

							(*som_Ligado) = true;
						}
						break;

					case 1:
						creditos(window_Renderer);
						break;

					case 2:
						controle(window_Renderer);
						break;
					}

					break;

				case SDLK_ESCAPE:

					settings = false;

					break;
				}
			} // Fim do switch das teclas
		} // Fim do loop de eventos

		SDL_RenderCopy(window_Renderer, background_Texture, NULL, NULL);
		SDL_RenderCopy(window_Renderer, botao_Voltar_Texture, NULL, &botao_Voltar_Rect);
		SDL_RenderCopy(window_Renderer, botoes_Texture, &botoes_Apagados_Clip, &botoes_Apagados_Rect);
		SDL_RenderCopy(window_Renderer, botoes_Texture, &botao_Acesso_Clip, &botao_Acesso_Rect);
		SDL_RenderCopy(window_Renderer, seta_Menu_Texture, &seta_Clip[seta_Sprite / 32], &seta_Rect);

		seta_Sprite += 1;

		if (seta_Sprite / 256 == 1)
		{
			seta_Sprite = 0;
		}


	} // Fim do while(settings)


	// Finalizando das settings
	SDL_DestroyTexture(botao_Voltar_Texture);
	SDL_DestroyTexture(botoes_Texture);

	botoes_Texture = NULL;
	botao_Voltar_Texture = NULL;

} // Fim da função settings


void menu(SDL_Renderer* window_Renderer, SDL_Surface* window_Surface, bool* load_game, bool* som_Ligado)
{
	SDL_Texture* background_Texture = load_texture("imagens/bg menu.png", window_Renderer);

	// ------------------------------- //

	SDL_Texture* seta_Menu_Texture = load_texture("imagens/seta menu.png", window_Renderer);

	SDL_Rect seta_Rect; // Rect do local onde a setinha será renderizada
	seta_Rect.x = (window_Surface->w) / 4 - 16 * 5;
	seta_Rect.y = (window_Surface->h) / 2;
	seta_Rect.w = 16 * 5;
	seta_Rect.h = 16 * 5;

	SDL_Rect seta_Clip[8]; // Rect (clip) do sprite da seta
	for (int i = 0; i < 8; i++)
	{
		seta_Clip[i].x = 16 * i;
		seta_Clip[i].y = 0;
		seta_Clip[i].w = 16;
		seta_Clip[i].h = 16;
	}

	// ------------------------------- //

	SDL_Texture* botoes_Texture = load_texture("imagens/botoes menu.png", window_Renderer);

	SDL_Rect botoes_Apagados_Rect; // Rect do local onde os botões serão renderizados
	botoes_Apagados_Rect.x = (window_Surface->w) / 4;
	botoes_Apagados_Rect.y = (window_Surface->h) / 2;
	botoes_Apagados_Rect.w = 80 * 7;
	botoes_Apagados_Rect.h = 48 * 7;

	SDL_Rect botoes_Apagados_Clip; // Rect (clip) para todos os botões apagados
	botoes_Apagados_Clip.x = 0;
	botoes_Apagados_Clip.y = 0;
	botoes_Apagados_Clip.w = 80;
	botoes_Apagados_Clip.h = 48;

	SDL_Rect botao_Acesso_Rect;
	botao_Acesso_Rect.x = (window_Surface->w) / 4;
	botao_Acesso_Rect.y = (window_Surface->h) / 2 + (16 * 7 * 0);
	botao_Acesso_Rect.w = 80 * 7;
	botao_Acesso_Rect.h = 16 * 7;

	SDL_Rect botao_Acesso_Clip;
	botao_Acesso_Clip.x = 0;
	botao_Acesso_Clip.y = 48 + 16 * 0;
	botao_Acesso_Clip.w = 80;
	botao_Acesso_Clip.h = 16;



	// ------------------------------- //

	int seta_Posicao = 0;
	int seta_Sprite = 1;

	SDL_Event event;
	bool menu = true;

	while (menu)
	{
		SDL_RenderPresent(window_Renderer);

		while (SDL_PollEvent(&event) != 0) // Enquanto existir evento o loop continua
		{
			// Evento: fechar main_Window
			if (event.type == SDL_QUIT)
			{
				menu = false;
			}
			// Evento: tecla pressionada
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_DOWN:
					if (seta_Posicao + 1 <= 2)
					{
						seta_Rect.y += 120;
						seta_Posicao += 1;

						alterar_retangulo(&botao_Acesso_Rect, 0, +(16 * 7), 0, 0);
						alterar_retangulo(&botao_Acesso_Clip, 0, +(16), 0, 0);
					}
					break;

				case SDLK_UP:
					if (seta_Posicao - 1 >= 0)
					{
						seta_Rect.y -= 120;
						seta_Posicao -= 1;

						alterar_retangulo(&botao_Acesso_Rect, 0, -(16 * 7), 0, 0);
						alterar_retangulo(&botao_Acesso_Clip, 0, -(16), 0, 0);
					}
					break;

				case SDLK_s:
					if (seta_Posicao + 1 <= 2)
					{
						seta_Rect.y += 120;
						seta_Posicao += 1;

						alterar_retangulo(&botao_Acesso_Rect, 0, +(16 * 7), 0, 0);
						alterar_retangulo(&botao_Acesso_Clip, 0, +(16), 0, 0);
					}
					break;

				case SDLK_w:
					if (seta_Posicao - 1 >= 0)
					{
						seta_Rect.y -= 120;
						seta_Posicao -= 1;

						alterar_retangulo(&botao_Acesso_Rect, 0, -(16 * 7), 0, 0);
						alterar_retangulo(&botao_Acesso_Clip, 0, -(16), 0, 0);
					}
					break;

				case SDLK_RETURN:
					// swittch que desfine a escolha do jogador em relação aos botões
					switch (seta_Posicao) // 0 - New game | 1 - Load game | 2 - settings
					{
					case 0:
						menu = false;
						break;
					case 1:
						menu = false;
						(*load_game) = true;
						break;
					case 2:
						settings(window_Renderer, window_Surface, seta_Menu_Texture, seta_Clip, background_Texture, som_Ligado);
						break;
					}
					break;

				case SDLK_SPACE:
					// swittch que desfine a escolha do jogador em relação aos botões
					switch (seta_Posicao) // 0 - New game | 1 - Load game | 2 - settings
					{
					case 0:
						menu = false;
						break;
					case 1:
						menu = false;
						(*load_game) = true;
						break;
					case 2:
						SDL_RenderCopy(window_Renderer, background_Texture, NULL, NULL);
						settings(window_Renderer, window_Surface, seta_Menu_Texture, seta_Clip, background_Texture, som_Ligado);
						break;
					}
					break;
				}
			} // Fim do switch das teclas
		} // Fim do loop de eventos

		SDL_RenderCopy(window_Renderer, background_Texture, NULL, NULL);
		SDL_RenderCopy(window_Renderer, botoes_Texture, &botoes_Apagados_Clip, &botoes_Apagados_Rect);
		SDL_RenderCopy(window_Renderer, seta_Menu_Texture, &seta_Clip[seta_Sprite / 32], &seta_Rect);
		SDL_RenderCopy(window_Renderer, botoes_Texture, &botao_Acesso_Clip, &botao_Acesso_Rect);

		seta_Sprite += 1;

		if (seta_Sprite / 256 == 1)
		{
			seta_Sprite = 0;
		}

	} // fim do while(menu)

	// Finalizando o menu
	SDL_DestroyTexture(background_Texture);
	SDL_DestroyTexture(botoes_Texture);
	SDL_DestroyTexture(seta_Menu_Texture);

	background_Texture = NULL;
	botoes_Texture = NULL;
	seta_Menu_Texture = NULL;

} // fim da função menu



// --------------------------------------------------------------------------------------- //


void escolher_dificuldade(SDL_Renderer* window_Renderer, SDL_Surface* window_Surface, int* dificuldade)
{
	SDL_Texture* dificulty_Texture = load_texture("imagens/bg dificuldade.png", window_Renderer); //textura do background de dificuldade

	bool new_game = true;
	int seta_Posicao = 0;
	int seta_Sprite = 1;
	SDL_Event event;

	//-----------------------------//

	SDL_Texture* seta_Menu_Texture = load_texture("imagens/seta menu.png", window_Renderer);

	SDL_Rect seta_Rect; // Rect do local onde a setinha será renderizada
	seta_Rect.x = (window_Surface->w) / 4 - 16 * 5;
	seta_Rect.y = (window_Surface->h) / 2;
	seta_Rect.w = 16 * 5;
	seta_Rect.h = 16 * 5;

	SDL_Rect seta_Clip[8]; // Rect (clip) do sprite da seta
	for (int i = 0; i < 8; i++)
	{
		seta_Clip[i].x = 16 * i;
		seta_Clip[i].y = 0;
		seta_Clip[i].w = 16;
		seta_Clip[i].h = 16;
	}

	//----------------------------//

	SDL_Texture* botoes_Texture = load_texture("imagens/botoes dificuldade.png", window_Renderer);

	SDL_Rect botoes_Apagados_Rect; // Rect do local onde os botões serão renderizados
	botoes_Apagados_Rect.x = (window_Surface->w) / 4;
	botoes_Apagados_Rect.y = (window_Surface->h) / 2;
	botoes_Apagados_Rect.w = 80 * 7;
	botoes_Apagados_Rect.h = 48 * 7;

	SDL_Rect botoes_Apagados_Clip; // Rect (clip) para todos os botões apagados
	botoes_Apagados_Clip.x = 0;
	botoes_Apagados_Clip.y = 0;
	botoes_Apagados_Clip.w = 80;
	botoes_Apagados_Clip.h = 48;

	SDL_Rect botoes_Acessos_Rect[3]; // Array de rects do local onde o botão acesso acesso será renderizado
	for (int i = 0; i < 3; i++)
	{
		botoes_Acessos_Rect[i].x = (window_Surface->w) / 4;
		botoes_Acessos_Rect[i].y = (window_Surface->h) / 2 + (16 * 7 * i);
		botoes_Acessos_Rect[i].w = 80 * 7;
		botoes_Acessos_Rect[i].h = 16 * 7;
	}

	SDL_Rect botoes_Acessos_Clip[3]; // Array de Rects, um para cada botão acesso
	for (int i = 0; i < 3; i++)
	{
		botoes_Acessos_Clip[i].x = 0;
		botoes_Acessos_Clip[i].y = 48 + 16 * i;
		botoes_Acessos_Clip[i].w = 80;
		botoes_Acessos_Clip[i].h = 16;
	}

	// ------------------------------- //

	while (new_game)
	{
		SDL_RenderPresent(window_Renderer);

		while (SDL_PollEvent(&event) != 0) // Enquanto existir evento o loop continua
		{
			// Evento: fechar main_Window
			if (event.type == SDL_QUIT)
			{
				new_game = false;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym) // Evento: tecla pressionada
				{
				case SDLK_DOWN:
					if (seta_Posicao + 1 <= 2)
					{
						seta_Rect.y += 120;
						seta_Posicao += 1;
					}
					break;

				case SDLK_UP:
					if (seta_Posicao - 1 >= 0)
					{
						seta_Rect.y -= 120;
						seta_Posicao -= 1;
					}
					break;
				case SDLK_s:
					if (seta_Posicao + 1 <= 2)
					{
						seta_Rect.y += 120;
						seta_Posicao += 1;
					}
					break;

				case SDLK_w:
					if (seta_Posicao - 1 >= 0)
					{
						seta_Rect.y -= 120;
						seta_Posicao -= 1;
					}
					break;
				case SDLK_RETURN:
					new_game = false;
					switch (seta_Posicao) //seta varia de 0 a 2
					{
					case 0:
						*dificuldade = 0; //facil
						break;

					case 1:
						*dificuldade = 20; //medio
						break;

					case 2:
						*dificuldade = 40; //dificil
						break;
					}
					break;

				case SDLK_SPACE:
					new_game = false;
					switch (seta_Posicao) //seta varia de 0 a 2
					{
					case 0:
						*dificuldade = 0; //facil
						break;

					case 1:
						*dificuldade = 20; //medio
						break;

					case 2:
						*dificuldade = 40; //dificil
						break;
					}
					break;
				}
			}

		} // Fim do loop de eventos

		SDL_RenderCopy(window_Renderer, dificulty_Texture, NULL, NULL);
		SDL_RenderCopy(window_Renderer, botoes_Texture, &botoes_Apagados_Clip, &botoes_Apagados_Rect);
		SDL_RenderCopy(window_Renderer, seta_Menu_Texture, &seta_Clip[seta_Sprite / 32], &seta_Rect);
		SDL_RenderCopy(window_Renderer, botoes_Texture, &botoes_Acessos_Clip[seta_Posicao], &botoes_Acessos_Rect[seta_Posicao]);

		seta_Sprite += 1;

		if (seta_Sprite / 256 == 1)
		{
			seta_Sprite = 0;
		}
	} // fim do while(new_game)
	
	  
	// Finalizando a escolha de dificuldades
	SDL_DestroyTexture(dificulty_Texture);
	SDL_DestroyTexture(botoes_Texture);
	SDL_DestroyTexture(seta_Menu_Texture);

	dificulty_Texture = NULL;
	botoes_Texture = NULL;
	seta_Menu_Texture = NULL;

}// Fim da função escolha_dificuldade()


void inicio_jornal(SDL_Renderer* window_Renderer, SDL_Surface* window_Surface)
{
	SDL_Texture* jornal_Texture = load_texture("imagens/jornal detetive 1.png", window_Renderer);

	bool Inicio_jornal = true;
	SDL_Event event;

	while (Inicio_jornal)
	{
		SDL_RenderPresent(window_Renderer);

		while (SDL_PollEvent(&event) != 0) // Enquanto existir evento o loop continua
		{
			// Evento: fechar main_Window
			if (event.type == SDL_QUIT)
			{
				Inicio_jornal = false;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)// Evento: tecla pressionada
				{
				case SDLK_RETURN:
					Inicio_jornal = false;
					break;

				case SDLK_SPACE:
					Inicio_jornal = false;
					break;
				}
			}

		} // Fim do loop de eventos

		SDL_RenderCopy(window_Renderer, jornal_Texture, NULL, NULL);

	} // fim do while(inicio_jornal)

	SDL_DestroyTexture(jornal_Texture);

	jornal_Texture = NULL;

}// Finalizando o inicio_jornal


// --------------------------------------------------------------------------------------- //

void cenario_1(SDL_Renderer* window_Renderer, SDL_Surface* window_Surface, SDL_Rect* main_Rect, bool som_Ligado, int* cenarios_Completos)
{
	Mix_Music* musica_jogo = Mix_LoadMUS("Recursos/Audios/Som dos Cravos.wav");

	if (som_Ligado)
	{
		musica(musica_jogo, 1);
	}

	coloca_fundo_preto(window_Renderer);

	int cenario_Width = 240;  //15x16
	int cenario_Height = 160; //10x16
	int amplificador = 3;
	int lado = 16;

	SDL_Rect cenario_Rect;
	cenario_Rect.x = 1280 / 2 - cenario_Width / 2 * amplificador;
	cenario_Rect.y = 720 / 2 - cenario_Height / 2 * amplificador;
	cenario_Rect.w = cenario_Width * amplificador;
	cenario_Rect.h = cenario_Height * amplificador;

	SDL_RenderSetViewport(window_Renderer, &cenario_Rect);

	SDL_Rect grid[10][15];

	for (int linha = 0; linha < 10; linha++)
	{
		for (int coluna = 0; coluna < 15; coluna++)
		{
			grid[linha][coluna].x = lado * amplificador * coluna;
			grid[linha][coluna].y = lado * amplificador * linha;
			grid[linha][coluna].w = lado * amplificador;
			grid[linha][coluna].h = lado * amplificador;
		}
	}

	// ------------------------------- //

	char quarto_1[10][15] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
							  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
							  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
							  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
							  ' ', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', '_', '_', ' ', ' ', '_', '_',
							  ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_',
							  ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_',
							  ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', ' ', '_', '_',
							  ' ', ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', ' ', ' ', '_', '_',
							  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', ' ', ' ' };

	char quarto_2[10][15] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
							  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
							  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
							  ' ', '_', '_', '_', ' ', '_', '_', '_', '_', ' ', ' ', '_', ' ', ' ', ' ',
							  ' ', ' ', ' ', '_', ' ', ' ', ' ', ' ', '_', ' ', ' ', '_', ' ', ' ', ' ',
							  ' ', ' ', '_', '_', '_', ' ', '_', '_', '_', '_', '_', '_', ' ', ' ', ' ',
							  ' ', '_', '_', ' ', '_', '_', '_', '_', ' ', '_', '_', '_', '_', '_', '_',
							  ' ', '_', ' ', ' ', ' ', '_', ' ', ' ', '_', ' ', ' ', '_', ' ', ' ', ' ',
							  ' ', '_', '_', '_', ' ', '_', '_', '_', '_', '_', '_', '_', ' ', ' ', ' ', };



	// ------------------------------- //

	SDL_Texture* background_Texture_1 = load_texture("imagens/casa 1 quarto 1.png", window_Renderer);

	SDL_Texture* background_Texture_2 = load_texture("imagens/casa 1 quarto 2.png", window_Renderer);


	SDL_Texture* detetive_Costa_1_Texture = load_texture("imagens/detetive costa 1.png", window_Renderer);
	SDL_Texture* detetive_Costa_2_Texture = load_texture("imagens/detetive costa 2.png", window_Renderer);
	SDL_Texture* detetive_Costa_3_Texture = load_texture("imagens/detetive costa 3.png", window_Renderer);

	SDL_Texture* detetive_Frente_1_Texture = load_texture("imagens/detetive frente 1.png", window_Renderer);
	SDL_Texture* detetive_Frente_2_Texture = load_texture("imagens/detetive frente 2.png", window_Renderer);
	SDL_Texture* detetive_Frente_3_Texture = load_texture("imagens/detetive frente 3.png", window_Renderer);

	SDL_Texture* detetive_Lado_Direito_1_Texture = load_texture("imagens/detetive lado dir 1.png", window_Renderer);
	SDL_Texture* detetive_Lado_Direito_2_Texture = load_texture("imagens/detetive lado dir 2.png", window_Renderer);
	SDL_Texture* detetive_Lado_Direito_3_Texture = load_texture("imagens/detetive lado dir 3.png", window_Renderer);

	SDL_Texture* detetive_Lado_Esquerdo_1_Texture = load_texture("imagens/detetive lado esq 1.png", window_Renderer);
	SDL_Texture* detetive_Lado_Esquerdo_2_Texture = load_texture("imagens/detetive lado esq 2.png", window_Renderer);
	SDL_Texture* detetive_Lado_Esquerdo_3_Texture = load_texture("imagens/detetive lado esq 3.png", window_Renderer);


	SDL_Texture* moveis_Texture = load_texture("imagens/moveis.png", window_Renderer);

	// ------------------------------- //

	SDL_Texture* pouca_Visibilidade1_Texture = load_texture("imagens/luz sem lanterna 1.png", window_Renderer); // quarto 1 com lanterna
	SDL_Texture* pouca_Visibilidade2_Texture = load_texture("imagens/luz sem lanterna 2.png", window_Renderer); // quarto 2 com lanterna

	SDL_Texture* lanterna_Visibilidade1_Texture = load_texture("imagens/luz com lanterna 1.png", window_Renderer); // quarto 1 sem lanterna
	SDL_Texture* lanterna_Visibilidade2_Texture = load_texture("imagens/luz com lanterna 2.png", window_Renderer); // quanto 2 sem lanterna

	SDL_Texture* imagem_Preta_Texture = load_texture("imagens/fundo preto.png", window_Renderer);

	SDL_Rect imagem_Preta_Rect;
	imagem_Preta_Rect.x = 1280 + cenario_Width;
	imagem_Preta_Rect.y = 0;
	imagem_Preta_Rect.w = 640;
	imagem_Preta_Rect.h = 720*2;

	SDL_Texture* lanterna_Texture = load_texture("imagens/lanterna.png", window_Renderer);

	SDL_Rect lanterna_Rect;
	lanterna_Rect.x = grid[8][14].x + lado;
	lanterna_Rect.y = grid[8][14].y + lado;
	lanterna_Rect.w = lado;
	lanterna_Rect.h = lado;

	SDL_Texture* rosa_Texture = load_texture("imagens/rosa.png", window_Renderer);

	SDL_Rect rosa_Rect;
	rosa_Rect.x = grid[3][1].x;
	rosa_Rect.y = grid[3][1].y;
	rosa_Rect.w = lado;
	rosa_Rect.h = lado;

	// ------------------------------- //

	SDL_Rect detetive_Rect;
	detetive_Rect.x = grid[8][9].x - 16;
	detetive_Rect.y = grid[8][9].y - 16;
	detetive_Rect.w = 64;
	detetive_Rect.h = 64;

	SDL_Rect detetive_Rect_Hitbox = detetive_Rect;
	detetive_Rect_Hitbox.x += detetive_Rect.w / 2;
	detetive_Rect_Hitbox.w /= 48;
	detetive_Rect_Hitbox.y += detetive_Rect.h / 2;
	detetive_Rect_Hitbox.h /= 48;

	SDL_Rect detetive_Luminosidade_Rect;
	detetive_Luminosidade_Rect.x = 0;
	detetive_Luminosidade_Rect.y = 0;
	detetive_Luminosidade_Rect.w = 1280 + cenario_Width;
	detetive_Luminosidade_Rect.h = 720 + cenario_Height;

	// ------------------------------- //

	// booleanas de movimento
	bool esq = false;
	bool dir = false;
	bool cima = false;
	bool baixo = false;

	// contadores de frames
	int frame_Detetive = 0;

	char detetive = 'D';
	int detetive_Linha = 5;
	int detetive_Coluna = 7;

	int detetive_Lado = 3; // WASD = 1234 respectivamente
						  //  1234

	int num_cenario = 1; // 1 = quarto 1 | 2 = quarto 2

	bool objetivo_Completo = false;
	bool possui_Lanterna = false;
	bool possui_Rosa = false;

	SDL_Event event;
	bool cenario = true;

	SDL_RenderCopy(window_Renderer, background_Texture_1, NULL, NULL);
	SDL_RenderCopy(window_Renderer, detetive_Costa_1_Texture, NULL, &detetive_Rect);

	SDL_Texture* hitbox_Texture = load_texture("imagens/fundo preto.png", window_Renderer); // <---- apenas para debugar

	while (cenario)
	{
		SDL_RenderCopy(window_Renderer, hitbox_Texture, NULL, &detetive_Rect_Hitbox); // <---- apenas para debugar

		SDL_RenderPresent(window_Renderer);

		while (SDL_PollEvent(&event) != 0) // Enquanto existir evento o loop continua
		{
			// Evento: fechar main_Window
			if (event.type == SDL_QUIT)
			{
				cenario = false;
			}
			// Evento: tecla pressionada
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					cenario = false;
					break;

				case SDLK_w:
					cima = true;

					detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h * 3 / 4;
					break;

				case SDLK_a:
					esq = true;

					detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w * 3 / 4;
					break;

				case SDLK_s:
					baixo = true;

					detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h / 4;
					break;

				case SDLK_d:
					dir = true;

					detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w / 4;
					break;

				case SDLK_k:

					if ( (detetive_Linha == 8 || detetive_Linha == 7) && (detetive_Coluna == 14 || detetive_Coluna == 13) )
					{
						possui_Lanterna = true;
					}
					else if (detetive_Linha == 3 && detetive_Coluna == 1)
					{
						possui_Rosa = true;
						objetivo_Completo = true;
					}
					break;

				}
			}
			else if (event.type == SDL_KEYUP)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_w:
					cima = false;

					detetive_Lado = 1;

					detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h / 2;
					break;

				case SDLK_a:
					esq = false;

					detetive_Lado = 2;

					detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w / 2;
					break;

				case SDLK_s:
					baixo = false;

					detetive_Lado = 3;

					detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h / 2;
					break;

				case SDLK_d:
					dir = false;

					detetive_Lado = 4;

					detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w / 2;
					break;
				}
			} // Fim do switch das teclas

		} // Fim do loop de eventos

		// Coloca o detetive na matriz em função do seu retangulo no grid
		for (int linha = 0; linha < 10; linha++)
		{
			for (int coluna = 0; coluna < 15; coluna++)
			{
				if (SDL_HasIntersection(&detetive_Rect_Hitbox, &grid[linha][coluna]))
				{
					printf("detetive_Linha = %i \n", linha);
					printf("detetive_Coluna = %i \n\n", coluna);

					if (num_cenario == 1 && quarto_1[linha][coluna] == '_')
					{
						quarto_1[linha][coluna] = detetive;
					}
					else if (num_cenario == 2 && quarto_2[linha][coluna] == '_')
					{
						quarto_2[linha][coluna] = detetive;
					}

					detetive_Linha = linha;
					detetive_Coluna = coluna;
				}
				else
				{
					if (num_cenario == 1 && quarto_1[linha][coluna] == 'D')
					{
						quarto_1[linha][coluna] = '_';
					}
					else if (num_cenario == 2 && quarto_2[linha][coluna] == 'D')
					{
						quarto_2[linha][coluna] = '_';
					}
				}
			}
		}

		// Movimentação do detetive na matriz da quato 1 ou 2
		if (cima == true)
		{
			if (num_cenario == 1)
			{
				if (quarto_1[detetive_Linha - 1][detetive_Coluna] == '_')
				{
					detetive_Rect.y -= 8;
					detetive_Rect_Hitbox.y -= 8;
					detetive_Luminosidade_Rect.y -= 8;
					imagem_Preta_Rect.y -= 8;
				}
			}
			else if (num_cenario == 2)
			{
				if (quarto_2[detetive_Linha - 1][detetive_Coluna] == '_')
				{
					detetive_Rect.y -= 8;
					detetive_Rect_Hitbox.y -= 8;
					detetive_Luminosidade_Rect.y -= 8;
					imagem_Preta_Rect.y -= 8;
				}
			}

		}
		else if (esq == true)
		{
			if (num_cenario == 1)
			{
				if (quarto_1[detetive_Linha][detetive_Coluna - 1] == '_')
				{
					detetive_Rect.x -= 8;
					detetive_Rect_Hitbox.x -= 8;
					detetive_Luminosidade_Rect.x -= 8;
					imagem_Preta_Rect.x -= 8;
				}
			}
			else if (num_cenario == 2)
			{
				if (quarto_2[detetive_Linha][detetive_Coluna - 1] == '_')
				{
					detetive_Rect.x -= 8;
					detetive_Rect_Hitbox.x -= 8;
					detetive_Luminosidade_Rect.x -= 8;
					imagem_Preta_Rect.x -= 8;
				}
			}

		}
		else if (baixo == true)
		{
			if (num_cenario == 1)
			{
				if (quarto_1[detetive_Linha + 1][detetive_Coluna] == '_')
				{
					detetive_Rect.y += 8;
					detetive_Rect_Hitbox.y += 8;
					detetive_Luminosidade_Rect.y += 8;
					imagem_Preta_Rect.y += 8;
				}
			}
			else if (num_cenario == 2)
			{
				if (quarto_2[detetive_Linha + 1][detetive_Coluna] == '_')
				{
					detetive_Rect.y += 8;
					detetive_Rect_Hitbox.y += 8;
					detetive_Luminosidade_Rect.y += 8;
					imagem_Preta_Rect.y += 8;
				}
			}
		}
		else if (dir == true)
		{
			if (num_cenario == 1)
			{
				if (quarto_1[detetive_Linha][detetive_Coluna + 1] == '_')
				{
					detetive_Rect.x += 8;
					detetive_Rect_Hitbox.x += 8;
					detetive_Luminosidade_Rect.x += 8;
					imagem_Preta_Rect.x += 8;
				}
			}
			else if (num_cenario == 2)
			{
				if (quarto_2[detetive_Linha][detetive_Coluna + 1] == '_')
				{
					detetive_Rect.x += 8;
					detetive_Rect_Hitbox.x += 8;
					detetive_Luminosidade_Rect.x += 8;
					imagem_Preta_Rect.x += 8;
				}
			}
		}

		// Checa em que sala o detetive está e, em seguida, as suas coordenadas
		if (num_cenario == 1) // quarto 1
		{
			// Se o detetive estivar nessas coordenadas do mapa ele passa para o quarto 2
			if (detetive_Linha == 6 && detetive_Coluna == 2)
			{
				num_cenario = 2;

				detetive_Linha = 6;
				detetive_Coluna = 13;

				detetive_Rect.x = grid[6][13].x - 16;
				detetive_Rect.y = grid[6][13].y - 16;

				detetive_Rect_Hitbox.x = grid[6][13].x - 16 + detetive_Rect.w / 2;
				detetive_Rect_Hitbox.y = grid[6][13].y - 16 + detetive_Rect.h / 2;
			}
			// Se o detetive estiver nessas coordenadas do mapa e tiver completado sua missão, então ele volta para a seleção de cenários (finalizando essa fase)
			else if (detetive_Linha == 9 && detetive_Coluna == 9 && objetivo_Completo)
			{
				SDL_RenderSetViewport(window_Renderer, main_Rect);

				cenario = false;
			}
		}
		else if (num_cenario == 2) // quarto 2
		{
			// Se o detetive estivar nessas coordenadas do mapa ele passa para o quarto 1
			if (detetive_Linha == 6 && detetive_Coluna == 14)
			{
				num_cenario = 1;

				detetive_Linha = 6;
				detetive_Coluna = 3;

				detetive_Rect.x = grid[6][3].x - 16;
				detetive_Rect.y = grid[6][3].y - 16;

				detetive_Rect_Hitbox.x = grid[6][3].x - 16 + detetive_Rect.w / 2;
				detetive_Rect_Hitbox.y = grid[6][3].y - 16 + detetive_Rect.h / 2;
			}
		}

		// SDL copy das texturas do cenário

		if (num_cenario == 1)
		{
			SDL_RenderCopy(window_Renderer, background_Texture_1, NULL, NULL);
		}
		else if (num_cenario == 2)
		{
			SDL_RenderCopy(window_Renderer, background_Texture_2, NULL, NULL);
		}

		// SDL copy dos itens pegaveis do cenario

		if (num_cenario == 1)
		{
			if (!possui_Lanterna)
			{
				SDL_RenderCopy(window_Renderer, lanterna_Texture, NULL, &lanterna_Rect);
			}
		}
		else if (num_cenario == 2)
		{
			if (!possui_Rosa)
			{
				SDL_RenderCopy(window_Renderer, rosa_Texture, NULL, &rosa_Rect);
			}
		}

		// SDL copy das texturas do detetive

		if (cima)
		{
			switch (frame_Detetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive_Costa_1_Texture, NULL, &detetive_Rect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive_Costa_2_Texture, NULL, &detetive_Rect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive_Costa_3_Texture, NULL, &detetive_Rect);
				break;
			}
		}
		else if (esq)
		{
			switch (frame_Detetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Esquerdo_1_Texture, NULL, &detetive_Rect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Esquerdo_2_Texture, NULL, &detetive_Rect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Esquerdo_3_Texture, NULL, &detetive_Rect);
				break;
			}
		}
		else if (baixo)
		{
			switch (frame_Detetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive_Frente_1_Texture, NULL, &detetive_Rect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive_Frente_2_Texture, NULL, &detetive_Rect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive_Frente_3_Texture, NULL, &detetive_Rect);
				break;
			}
		}
		else if (dir)
		{
			switch (frame_Detetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Direito_1_Texture, NULL, &detetive_Rect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Direito_2_Texture, NULL, &detetive_Rect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Direito_3_Texture, NULL, &detetive_Rect);
				break;
			}
		}
		else
		{
			if (detetive_Lado == 1)
			{
				SDL_RenderCopy(window_Renderer, detetive_Costa_1_Texture, NULL, &detetive_Rect);
			}
			else if (detetive_Lado == 2)
			{
				SDL_RenderCopy(window_Renderer, detetive_Lado_Esquerdo_2_Texture, NULL, &detetive_Rect);
			}
			else if (detetive_Lado == 3)
			{
				SDL_RenderCopy(window_Renderer, detetive_Frente_1_Texture, NULL, &detetive_Rect);
			}
			else if (detetive_Lado == 4)
			{
				SDL_RenderCopy(window_Renderer, detetive_Lado_Direito_2_Texture, NULL, &detetive_Rect);
			}
		}

		// ------------- //

		frame_Detetive += 1;

		if (frame_Detetive == 3)
		{
			frame_Detetive = 0;
		}

		// ------------- //

		// SDL copy das teturas que ficam por cima do detetive

		if (num_cenario == 1)
		{
			if (possui_Lanterna)
			{
				SDL_RenderSetViewport(window_Renderer, main_Rect);

				SDL_RenderCopy(window_Renderer, lanterna_Visibilidade1_Texture, NULL, &detetive_Luminosidade_Rect);
				
				SDL_RenderSetViewport(window_Renderer, &cenario_Rect);
			}
			else
			{
				SDL_RenderSetViewport(window_Renderer, main_Rect);

				SDL_RenderCopy(window_Renderer, pouca_Visibilidade1_Texture, NULL, &detetive_Luminosidade_Rect);
				
				SDL_RenderSetViewport(window_Renderer, &cenario_Rect);
			}
		}
		else if (num_cenario == 2)
		{
			SDL_RenderCopy(window_Renderer, moveis_Texture, NULL, NULL);

			if (possui_Lanterna)
			{
				SDL_RenderSetViewport(window_Renderer, main_Rect);

				SDL_RenderCopy(window_Renderer, imagem_Preta_Texture, NULL, &imagem_Preta_Rect);

				SDL_RenderCopy(window_Renderer, lanterna_Visibilidade2_Texture, NULL, &detetive_Luminosidade_Rect);
			
				SDL_RenderSetViewport(window_Renderer, &cenario_Rect);
			}
			else
			{
				SDL_RenderSetViewport(window_Renderer, main_Rect);

				SDL_RenderCopy(window_Renderer, imagem_Preta_Texture, NULL, &imagem_Preta_Rect);

				SDL_RenderCopy(window_Renderer, pouca_Visibilidade2_Texture, NULL, &detetive_Luminosidade_Rect);
			
				SDL_RenderSetViewport(window_Renderer, &cenario_Rect);
			}
		}

		// ------------- //

		SDL_Delay(50); // Fim da logica da movimentação e renderização

		// ------------- //

		// Mostra o mapa da delegacia


		for (int linha = 0; linha < 10; linha++)
		{
			for (int coluna = 0; coluna < 15; coluna++)
			{
				if (num_cenario == 1)
				{
					printf("%c ", quarto_1[linha][coluna]);
				}
				else if (num_cenario == 2)
				{
					printf("%c ", quarto_2[linha][coluna]);
				}
			}
			printf("\n");
		}

	} // Fim do while(cenario)

	// Finalizando o cenario

	*cenarios_Completos = 1;

	SDL_RenderSetViewport(window_Renderer, main_Rect);

	SDL_DestroyTexture(background_Texture_1);
	SDL_DestroyTexture(background_Texture_2);

	SDL_DestroyTexture(detetive_Costa_1_Texture);
	SDL_DestroyTexture(detetive_Costa_2_Texture);
	SDL_DestroyTexture(detetive_Costa_3_Texture);
	SDL_DestroyTexture(detetive_Frente_1_Texture);
	SDL_DestroyTexture(detetive_Frente_2_Texture);
	SDL_DestroyTexture(detetive_Frente_3_Texture);
	SDL_DestroyTexture(detetive_Lado_Direito_1_Texture);
	SDL_DestroyTexture(detetive_Lado_Direito_2_Texture);
	SDL_DestroyTexture(detetive_Lado_Direito_3_Texture);
	SDL_DestroyTexture(detetive_Lado_Esquerdo_1_Texture);
	SDL_DestroyTexture(detetive_Lado_Esquerdo_2_Texture);
	SDL_DestroyTexture(detetive_Lado_Esquerdo_3_Texture);

	background_Texture_1 = NULL;
	background_Texture_2 = NULL;

	detetive_Costa_1_Texture = NULL;
	detetive_Costa_2_Texture = NULL;
	detetive_Costa_3_Texture = NULL;
	detetive_Frente_1_Texture = NULL;
	detetive_Frente_2_Texture = NULL;
	detetive_Frente_3_Texture = NULL;
	detetive_Lado_Direito_1_Texture = NULL;
	detetive_Lado_Direito_2_Texture = NULL;
	detetive_Lado_Direito_3_Texture = NULL;
	detetive_Lado_Esquerdo_1_Texture = NULL;
	detetive_Lado_Esquerdo_2_Texture = NULL;
	detetive_Lado_Esquerdo_3_Texture = NULL;

	Mix_HaltMusic();

} // Fim da função cenario_1()

void cenario_2(SDL_Renderer * window_Renderer, SDL_Surface * window_Surface, SDL_Rect* main_Rect, bool som_Ligado, int* cenarios_Completos)
{
		Mix_Music* musica_jogo = Mix_LoadMUS("Recursos/Audios/Som dos Cravos.wav");

		if (som_Ligado)
		{
			musica(musica_jogo, 1);
		}

		coloca_fundo_preto(window_Renderer);

		int cenario_Width = 192;
		int cenario_Height = 144;
		int amplificador = 3;
		int lado = 16;

		SDL_Rect cenario_Rect;
		cenario_Rect.x = 1280 / 2 - cenario_Width / 2 * amplificador;
		cenario_Rect.y = 720 / 2 - cenario_Height / 2 * amplificador;
		cenario_Rect.w = cenario_Width * amplificador;
		cenario_Rect.h = cenario_Height * amplificador;

		SDL_RenderSetViewport(window_Renderer, &cenario_Rect);

		SDL_Rect grid[9][12];

		for (int linha = 0; linha < 9; linha++)
		{
			for (int coluna = 0; coluna < 12; coluna++)
			{
				grid[linha][coluna].x = lado * amplificador * coluna;
				grid[linha][coluna].y = lado * amplificador * linha;
				grid[linha][coluna].w = lado * amplificador;
				grid[linha][coluna].h = lado * amplificador;
			}
		}

		char cenario[9][12] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
						        ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', ' ', '_', '_', '_',
								' ', '_', '_', '_', '_', '_', '_', '_', ' ', '_', '_', '_',
								' ', '_', '_', '_', '_', '_', '_', '_', ' ', '_', '_', ' ',
								' ', '_', '_', '_', '_', ' ', ' ', '_', '_', '_', '_', ' ',
								' ', '_', '_', '_', '_', ' ', ' ', '_', '_', '_', '_', ' ',
								'_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_',
								' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
								' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ' };


		/*SDL_Rect mesa_Rect;
		mesa_Rect.x = grid[4][5].x;
		mesa_Rect.y = grid[4][5].y;
		mesa_Rect.w = lado*amplificador;
		mesa_Rect.h = lado*amplificador;*/

		SDL_Texture* background_cenario = load_texture("imagens/plataforma 0.png", window_Renderer);
		SDL_Texture* mesa_cenario_2_Texture = load_texture("imagens/mesa_cenario_2.png", window_Renderer);

		SDL_Texture* plataforma_1 = load_texture("imagens/plataforma 1.png", window_Renderer);
		SDL_Texture* plataforma_2 = load_texture("imagens/plataforma 2.png", window_Renderer);
		SDL_Texture* plataforma_3 = load_texture("imagens/plataforma 3.png", window_Renderer);
		SDL_Texture* plataforma_4 = load_texture("imagens/plataforma 4.png", window_Renderer);
		SDL_Texture* plataforma_k = load_texture("imagens/plataforma k.png", window_Renderer);

		SDL_Texture* detetive_costa_1 = load_texture("imagens/detetive costa 1.png", window_Renderer);
		SDL_Texture* detetive_costa_2 = load_texture("imagens/detetive costa 2.png", window_Renderer);
		SDL_Texture* detetive_costa_3 = load_texture("imagens/detetive costa 3.png", window_Renderer);

		SDL_Texture* detetive_frente_1 = load_texture("imagens/detetive frente 1.png", window_Renderer);
		SDL_Texture* detetive_frente_2 = load_texture("imagens/detetive frente 2.png", window_Renderer);
		SDL_Texture* detetive_frente_3 = load_texture("imagens/detetive frente 3.png", window_Renderer);

		SDL_Texture* detetive_lado_esquerdo_1 = load_texture("imagens/detetive lado esq 1.png", window_Renderer);
		SDL_Texture* detetive_lado_esquerdo_2 = load_texture("imagens/detetive lado esq 2.png", window_Renderer);
		SDL_Texture* detetive_lado_esquerdo_3 = load_texture("imagens/detetive lado esq 3.png", window_Renderer);

		SDL_Texture* detetive_lado_direito_1 = load_texture("imagens/detetive lado dir 1.png", window_Renderer);
		SDL_Texture* detetive_lado_direito_2 = load_texture("imagens/detetive lado dir 2.png", window_Renderer);
		SDL_Texture* detetive_lado_direito_3 = load_texture("imagens/detetive lado dir 3.png", window_Renderer);



		SDL_Rect detetive_Rect; // falta depender de onde veio
		detetive_Rect.x = grid[7][4].x - 16;
		detetive_Rect.y = grid[7][4].y - 16;
		detetive_Rect.w = 64;
		detetive_Rect.h = 64;

		SDL_Rect detetive_Rect_Hitbox = detetive_Rect;
		detetive_Rect_Hitbox.x += detetive_Rect.w / 2;
		detetive_Rect_Hitbox.w /= 48;
		detetive_Rect_Hitbox.y += detetive_Rect.h / 2;
		detetive_Rect_Hitbox.h /= 48;

		SDL_Rect texto_Rect;
		texto_Rect.x = cenario_Width / 2 - 200;
		texto_Rect.y = cenario_Height / 2 - 100;
		texto_Rect.w = 400;
		texto_Rect.h = 200;

		char detetive = 'D';
		int detetive_Linha = 7;
		int detetive_Coluna = 4;
		//-------------------------------------//

		int plataforma = 0;
		int detetive_Lado = 1;
		int sobe = 0, desce = 0, esquerda = 0, direita = 0;
		bool chatBox = false;

		//booleanas de movimento
		bool esq = false;
		bool dir = false;
		bool cima = false;
		bool baixo = false;

		//contadores de frames
		int frameDetetive = 0;

		bool objetivo_Concluido = false;

		//função booleana de execução do loop e criação da variavel atribuida a eventos
		bool executando = true;
		SDL_Event event;

		SDL_RenderCopy(window_Renderer, background_cenario, NULL, NULL);

		// SDL_Texture* hitbox_Texture = load_texture("imagens/fundo preto.png", window_Renderer); // <---- apenas para debugar


		//loop principal do jogo
		while (executando)
		{
			//eventos de comando do teclado/mouse
			while (SDL_PollEvent(&event))
			{
				// SDL_RenderCopy(window_Renderer, hitbox_Texture, NULL, &detetive_Rect_Hitbox); // <---- apenas para debugar

				SDL_RenderPresent(window_Renderer);

				//fechando a janela com ESC ou clique no X
				if (event.type == SDL_QUIT)
				{
					executando = false;
				}

				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					executando = false;
				}

				if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_a)
					{
						esq = true;
						detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w * 3 / 4;
					}
					else if (event.key.keysym.sym == SDLK_d)
					{
						dir = true;
						detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w / 4;
					}
					else if (event.key.keysym.sym == SDLK_w)
					{
						cima = true;
						detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h * 3 / 4;
					}
					else if (event.key.keysym.sym == SDLK_s)
					{
						baixo = true;
						detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h / 4;
					}
					else if (event.key.keysym.sym == SDLK_LEFT)
					{
						esq = true;
						detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w * 3 / 4;
					}
					else if (event.key.keysym.sym == SDLK_RIGHT)
					{
						dir = true;
						detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w / 4;
					}
					else if (event.key.keysym.sym == SDLK_UP)
					{
						cima = true;
						detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h * 3 / 4;
					}
					else if (event.key.keysym.sym == SDLK_DOWN)
					{
						baixo = true;
						detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h / 4;
					}
				}
				else if (event.type == SDL_KEYUP)
				{
					if (event.key.keysym.sym == SDLK_a)
					{
						esq = false;
						detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w / 2;
						detetive_Lado = 2;
					}
					else if (event.key.keysym.sym == SDLK_d)
					{
						dir = false;
						detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w / 2;
						detetive_Lado = 4;
					}
					else if (event.key.keysym.sym == SDLK_w)
					{
						cima = false;
						detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h / 2;
						detetive_Lado = 1;
					}
					else if (event.key.keysym.sym == SDLK_s)
					{
						baixo = false;
						detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h / 2;
						detetive_Lado = 3;
					}
					if (event.key.keysym.sym == SDLK_LEFT)
					{
						esq = false;
						detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w / 2;
						detetive_Lado = 2;
					}
					else if (event.key.keysym.sym == SDLK_RIGHT)
					{
						dir = false;
						detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w / 2;
						detetive_Lado = 4;
					}
					else if (event.key.keysym.sym == SDLK_UP)
					{
						cima = false;
						detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h / 2;
						detetive_Lado = 1;
					}
					else if (event.key.keysym.sym == SDLK_DOWN)
					{
						baixo = false;
						detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h / 2;
						detetive_Lado = 3;
					}
				}
			}


			for (int linha = 0; linha < 9; linha++)
			{
				for (int coluna = 0; coluna < 12; coluna++)
				{
					if (SDL_HasIntersection(&detetive_Rect_Hitbox, &grid[linha][coluna]))
					{
						printf("detetive_Linha = %i \n", linha);
						printf("detetive_Coluna = %i \n\n", coluna);

						if (cenario[detetive_Linha][detetive_Coluna] == '_')
						{
							//cenario[detetive_Linha][detetive_Coluna] = detetive;
						}

						detetive_Linha = linha;
						detetive_Coluna = coluna;
					}
					else
					{
						if (cenario[detetive_Linha][detetive_Coluna] == 'D')
						{
							printf("oi");
							cenario[detetive_Linha][detetive_Coluna] = '_';
						}
					}

				}
			}
			//---------------lógica----------------------//
			//------------------------------------------//

			//---DETETIVE---//

			//movimento do detetive
			if (esq == true)
			{
				if (cenario[detetive_Linha][detetive_Coluna - 1] == '_')
				{
					detetive_Rect.x -= 8;
					detetive_Rect_Hitbox.x -= 8;

					cenario[detetive_Linha][detetive_Coluna - 1] = '_';
				}

			}
			else if (dir == true)
			{
				if (cenario[detetive_Linha][detetive_Coluna + 1] == '_')
				{
					detetive_Rect.x += 8;
					detetive_Rect_Hitbox.x += 8;

					cenario[detetive_Linha][detetive_Coluna + 1] = '_';
				}

			}
			else if (cima == true)
			{
				if (cenario[detetive_Linha - 1][detetive_Coluna] == '_')
				{
					detetive_Rect.y -= 8;
					detetive_Rect_Hitbox.y -= 8;

					cenario[detetive_Linha - 1][detetive_Coluna] = '_';
				}

			}
			else if (baixo == true)
			{
				if (cenario[detetive_Linha + 1][detetive_Coluna] == '_')
				{
					detetive_Rect.y += 8;
					detetive_Rect_Hitbox.y += 8;

					cenario[detetive_Linha + 1][detetive_Coluna] = '_';
				}

			}

			//--COLISÕES--//



			//--------renderização---------//
			//----------------------------//


			//renderiza a textura na tela

			if (detetive_Linha == 6 && detetive_Coluna == 6 && plataforma == 0)
			{
				plataforma++;
			}
			else if (detetive_Linha == 6 && detetive_Coluna == 11 && plataforma == 1)
			{
				plataforma++;
			}
			else if (detetive_Linha == 2 && detetive_Coluna == 9 && plataforma == 2)
			{
				plataforma++;
			}
			else if (detetive_Linha == 3 && detetive_Coluna == 1 && plataforma == 3)
			{
				plataforma++;
			}


			if (plataforma == 0)
			{
				SDL_RenderCopy(window_Renderer, background_cenario, NULL, NULL);
			}
			else if (plataforma == 1)
			{
				SDL_RenderCopy(window_Renderer, plataforma_1, NULL, NULL);
			}
			else if (plataforma == 2)
			{
				SDL_RenderCopy(window_Renderer, plataforma_2, NULL, NULL);
			}
			else if (plataforma == 3)
			{
				SDL_RenderCopy(window_Renderer, plataforma_3, NULL, NULL);
			}
			else if (plataforma == 4)
			{
				SDL_RenderCopy(window_Renderer, plataforma_4, NULL, NULL);

				objetivo_Concluido = true;
			}


			if (esq)
			{
				switch (frameDetetive)
				{
				case 0:
					SDL_RenderCopy(window_Renderer, detetive_lado_esquerdo_1, NULL, &detetive_Rect);
					break;
				case 1:
					SDL_RenderCopy(window_Renderer, detetive_lado_esquerdo_2, NULL, &detetive_Rect);
					break;
				case 2:
					SDL_RenderCopy(window_Renderer, detetive_lado_esquerdo_3, NULL, &detetive_Rect);
					break;
				}
			}
			else if (dir)
			{
				switch (frameDetetive)
				{
				case 0:
					SDL_RenderCopy(window_Renderer, detetive_lado_direito_1, NULL, &detetive_Rect);
					break;
				case 1:
					SDL_RenderCopy(window_Renderer, detetive_lado_direito_2, NULL, &detetive_Rect);
					break;
				case 2:
					SDL_RenderCopy(window_Renderer, detetive_lado_direito_3, NULL, &detetive_Rect);
					break;
				}
			}
			else if (cima)
			{
				switch (frameDetetive)
				{
				case 0:
					SDL_RenderCopy(window_Renderer, detetive_costa_1, NULL, &detetive_Rect);
					break;
				case 1:
					SDL_RenderCopy(window_Renderer, detetive_costa_2, NULL, &detetive_Rect);
					break;
				case 2:
					SDL_RenderCopy(window_Renderer, detetive_costa_3, NULL, &detetive_Rect);
					break;
				}
			}
			else if (baixo)
			{
				switch (frameDetetive)
				{
				case 0:
					SDL_RenderCopy(window_Renderer, detetive_frente_1, NULL, &detetive_Rect);
					break;
				case 1:
					SDL_RenderCopy(window_Renderer, detetive_frente_2, NULL, &detetive_Rect);
					break;
				case 2:
					SDL_RenderCopy(window_Renderer, detetive_frente_3, NULL, &detetive_Rect);
					break;
				}
			}
			else
			{
				if (detetive_Lado == 1)
				{
					SDL_RenderCopy(window_Renderer, detetive_costa_1, NULL, &detetive_Rect);
				}
				else if (detetive_Lado == 2)
				{
					SDL_RenderCopy(window_Renderer, detetive_lado_esquerdo_1, NULL, &detetive_Rect);
				}
				else if (detetive_Lado == 3)
				{
					SDL_RenderCopy(window_Renderer, detetive_frente_1, NULL, &detetive_Rect);
				}
				else if (detetive_Lado == 4)
				{
					SDL_RenderCopy(window_Renderer, detetive_lado_direito_1, NULL, &detetive_Rect);
				}
			}

			// SDL Copy depois do detetive

			if (plataforma != 4)
			{
				SDL_RenderCopy(window_Renderer, mesa_cenario_2_Texture, NULL, NULL);
			}

			if (detetive_Linha == 8 && detetive_Coluna == 4 && objetivo_Concluido)
			{
				SDL_RenderSetViewport(window_Renderer, main_Rect);

				executando = false;
			}
			// Se o detetive estivar nessas coordenadas do mapa ele passa pra sala da esquerda delegacia


			//atualiza a renderização
			SDL_RenderPresent(window_Renderer);

			frameDetetive++;
			if (frameDetetive == 3)
				frameDetetive = 0;



			SDL_Delay(50);
		}

	// finalizando o cenário

	*cenarios_Completos = 2;

	background_cenario = NULL;

	detetive_costa_2 = NULL;
	detetive_costa_1 = NULL;
	detetive_costa_3 = NULL;

	detetive_frente_2 = NULL;
	detetive_frente_1 = NULL;
	detetive_frente_3 = NULL;

	detetive_lado_esquerdo_2 = NULL;
	detetive_lado_esquerdo_1 = NULL;
	detetive_lado_esquerdo_3 = NULL;
	detetive_lado_direito_2 = NULL;
	detetive_lado_direito_1 = NULL;
	detetive_lado_direito_3 = NULL;

	Mix_HaltMusic();

} // Fim da função cenario 2

void cenario_3(SDL_Renderer* window_Renderer, SDL_Surface* window_Surface, SDL_Rect* main_Rect, bool som_Ligado, int* cenarios_Completos)
{
	Mix_Music* musica_jogo = Mix_LoadMUS("Recursos/Audios/Som dos Cravos.wav");

	if (som_Ligado)
	{
		musica(musica_jogo, 1);
	}

	int SCREEN_WIDTH = 1280;
	int SCREEN_HEIGHT = 720;

	SDL_Rect cenario_Rect;
	cenario_Rect.x = 0;
	cenario_Rect.y = 0;
	cenario_Rect.w = 1080;
	cenario_Rect.h = 720;

	bool cenario_Completo = false;

	int cenario[22][34] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						   0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,
						   0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						   1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
						   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
						   0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						   0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						   0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						   0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,
						   0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,
						   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,
						   0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,
						   0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,
						   0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1 };

	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 34; j++) {
			printf("%i", cenario[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int detetiveLinha1 = 3, detetiveColuna1 = 2,
		detetiveLinha2 = 3, detetiveColuna2 = 3,
		detetiveLinha3 = 4, detetiveColuna3 = 2,
		detetiveLinha4 = 4, detetiveColuna4 = 3;

	cenario[detetiveLinha1][detetiveColuna1] = 2;
	cenario[detetiveLinha2][detetiveColuna2] = 2;
	cenario[detetiveLinha3][detetiveColuna3] = 2;
	cenario[detetiveLinha4][detetiveColuna4] = 2;

	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 34; j++) {
			printf("%i", cenario[i][j]);
		}
		printf("\n");
	}

	int sobe = 0, desce = 0, esquerda = 0, direita = 0;
	int bau = 0;
	int chave1 = 0, chave2 = 0, chave3 = 0, chave4 = 0;
	int cartaDeAmor = 0;
	int detetiveLado = 4;
	bool cartaLida = false;
	bool chatBox = false;

	//booleanas de movimento
	bool esq = false;
	bool dir = false;
	bool cima = false;
	bool baixo = false;

	//contadores de frames
	int frameAtual = 0;
	int frameDetetive = 0;
	int qtdFrame = 3;

	//função booleana de execução do loop e criação da variavel atribuida a eventos
	bool executando = true;
	SDL_Event click;

	//--Area de criação de retangulos :D --//

	SDL_Rect detetiveRect;
	detetiveRect.x = 64;
	detetiveRect.y = 96;
	detetiveRect.w = 64;
	detetiveRect.h = 64;

	SDL_Rect textoRect;
	textoRect.x = SCREEN_WIDTH / 2 - 200;
	textoRect.y = SCREEN_HEIGHT / 2 - 100;
	textoRect.w = 400;
	textoRect.h = 200;

	SDL_Rect cartaRect;
	cartaRect.x = SCREEN_WIDTH / 2 - 200;
	cartaRect.y = SCREEN_HEIGHT / 2 - 300;
	cartaRect.w = 400;
	cartaRect.h = 600;

	SDL_Rect itensRect[5];
	for (int i = 0, x = 425, d = 45; i < 5; i++)
	{
		itensRect[i].x = x;
		itensRect[i].y = 670;
		itensRect[i].w = 40;
		itensRect[i].h = 40;

		x += d;
	}

	//--fim da área de criação de retângulos--//

	loadImage(window_Renderer);

	//loop principal do jogo
	while (executando)
	{
		//eventos de comando do teclado/mouse
		while (SDL_PollEvent(&click))
		{
			//fechando a janela com ESC ou clique no X
			if (click.type == SDL_QUIT)
			{
				executando = false;
			}

			switch (click.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				executando = false;
			}

			if (click.type == SDL_KEYDOWN)
			{
				if (click.key.keysym.sym == SDLK_a)
				{
					esq = true;
				}
				else if (click.key.keysym.sym == SDLK_d)
				{
					dir = true;
				}
				else if (click.key.keysym.sym == SDLK_w)
				{
					cima = true;
				}
				else if (click.key.keysym.sym == SDLK_s)
				{
					baixo = true;
				}
				else if (click.key.keysym.sym == SDLK_k)
				{
					if (cenario[8][0] == 2 && cenario[8][1] == 2)
					{
						if (chave1 == 0 && detetiveLado == 3)
						{
							chatBox = true;
							chave1 = 1;
							printf("você adiquiriu a chave 1\n");
						}
						else
						{
							chatBox = false;
						}
					}

					else if (cenario[18][12] == 2 && detetiveLado == 3)
					{
						if (chave2 == 0)
						{
							chatBox = true;
							chave2 = 1;
							printf("você encontrou a chave 2 em baixo da cama!\n");
						}
						else
						{
							chatBox = false;
						}
					}

					else if (cenario[12][30] == 2)
					{
						if (chave2 == 1 && chave3 == 0 && detetiveLado == 2)
						{
							chatBox = true;
							chave3 = 1;
							chave2 = 3;
							printf("você adiquiriu a chave 3\n");
						}
						else
						{
							chatBox = false;
						}
					}

					else if (cenario[5][12] == 2 && detetiveLado == 3)
					{
						if (chave3 == 1 && chave4 == 0)
						{
							chatBox = true;
							chave4 = 1;
							chave3 = 3;
							printf("você adiquiriu a chave 4\n");
						}
						else
						{
							chatBox = false;
						}
					}

					else if (cenario[4][25] == 2 && cenario[4][26] == 2 && detetiveLado == 3)
					{
						if (bau == 0)
						{
							chatBox = true;
							bau = 1;
							printf("você adiquiriu um baú com 4 fechaduras!"
								" Se possuir as 4 chaves e estiver no local"
								" correto você poderá abri-lo\n");
						}
						else
						{
							chatBox = false;
						}
					}

					else if ((cenario[7][13] == 2 && cenario[7][14] == 2) && detetiveLado == 3)
					{
						if (chave1 == 1 && chave4 == 1 && bau == 1)
						{
							chatBox = true;
							cartaDeAmor = 1;
							chave1 = 3;
							chave4 = 3;
							bau = 3;
							printf("Você abriu o bau e encontrou uma carta, aperte k para ler!");
						}
						else
						{
							chatBox = false;
							cartaDeAmor++;
						}
					}
					if (cartaDeAmor == 2)
					{
						if (chatBox == false)
						{
							chatBox = true;
							cartaLida = true;
							printf("Dear ...");
							cenario_Completo = true;
						}
						else if (chatBox == true)
							chatBox = false;
					}

					if (cenario[3][3] == 2 && detetiveLado == 3 && cenario_Completo)
					{
						executando = false;
					}
				}
			}
			else if (click.type == SDL_KEYUP)
				if (click.key.keysym.sym == SDLK_a)
				{
					detetiveLado = 1;
					esq = false;
				}
				else if (click.key.keysym.sym == SDLK_d)
				{
					detetiveLado = 2;
					dir = false;
				}
				else if (click.key.keysym.sym == SDLK_w)
				{
					detetiveLado = 3;
					cima = false;
				}
				else if (click.key.keysym.sym == SDLK_s)
				{
					detetiveLado = 4;
					baixo = false;
				}
		}

		//---------------lógica----------------------//
		//------------------------------------------//

		if (chatBox == true && (cenario[8][1] != 2 && cenario[18][12] != 2 && cenario[12][30] != 2 && cenario[5][12] != 2
			&& cenario[4][25] != 2 && cenario[7][13] != 2))
		{
			chatBox = false;
		}

		//---DETETIVE---//

		//movimento do detetive
		if (esq == true)
		{
			if (cenario[detetiveLinha1][detetiveColuna1 - 1] == 0 && cenario[detetiveLinha3][detetiveColuna3 - 1] == 0)
			{
				detetiveRect.x -= 8;
				esquerda++;
				if (esquerda % 4 == 0)
				{
					cenario[detetiveLinha1][detetiveColuna1 + 1] = 0;
					cenario[detetiveLinha3][detetiveColuna3 + 1] = 0;
					detetiveColuna1--;
					detetiveColuna2--;
					detetiveColuna3--;
					detetiveColuna4--;
					cenario[detetiveLinha1][detetiveColuna1] = 2;
					cenario[detetiveLinha2][detetiveColuna2] = 2;
					cenario[detetiveLinha3][detetiveColuna3] = 2;
					cenario[detetiveLinha4][detetiveColuna4] = 2;
				}
			}
			for (int i = 0; i < 22; i++) {
				for (int j = 0; j < 34; j++) {
					printf("%i", cenario[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		else if (dir == true)
		{
			if (cenario[detetiveLinha2][detetiveColuna2 + 1] == 0 && cenario[detetiveLinha4][detetiveColuna4 + 1] == 0)
			{
				detetiveRect.x += 8;
				direita++;
				if (direita % 4 == 0)
				{
					cenario[detetiveLinha2][detetiveColuna2 - 1] = 0;
					cenario[detetiveLinha4][detetiveColuna2 - 1] = 0;
					detetiveColuna1++;
					detetiveColuna2++;
					detetiveColuna3++;
					detetiveColuna4++;
					cenario[detetiveLinha1][detetiveColuna1] = 2;
					cenario[detetiveLinha2][detetiveColuna2] = 2;
					cenario[detetiveLinha3][detetiveColuna3] = 2;
					cenario[detetiveLinha4][detetiveColuna4] = 2;
				}
			}
			for (int i = 0; i < 22; i++) {
				for (int j = 0; j < 34; j++) {
					printf("%i", cenario[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		else if (cima == true)
		{
			if (cenario[detetiveLinha1 - 1][detetiveColuna1] == 0 && cenario[detetiveLinha2 - 1][detetiveColuna2] == 0)
			{
				detetiveRect.y -= 8;
				sobe++;
				if (sobe % 4 == 0)
				{
					cenario[detetiveLinha1 + 1][detetiveColuna1] = 0;
					cenario[detetiveLinha2 + 1][detetiveColuna2] = 0;
					detetiveLinha1--;
					detetiveLinha2--;
					detetiveLinha3--;
					detetiveLinha4--;
					cenario[detetiveLinha1][detetiveColuna1] = 2;
					cenario[detetiveLinha2][detetiveColuna2] = 2;
					cenario[detetiveLinha3][detetiveColuna3] = 2;
					cenario[detetiveLinha4][detetiveColuna4] = 2;
				}
			}
			for (int i = 0; i < 22; i++) {
				for (int j = 0; j < 34; j++) {
					printf("%i", cenario[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		else if (baixo == true)
		{
			if (cenario[detetiveLinha3 + 1][detetiveColuna3] == 0 && cenario[detetiveLinha4 + 1][detetiveColuna4] == 0)
			{
				detetiveRect.y += 8;
				desce++;
				if (desce % 4 == 0)
				{
					cenario[detetiveLinha3 - 1][detetiveColuna3] = 0;
					cenario[detetiveLinha4 - 1][detetiveColuna4] = 0;
					detetiveLinha1++;
					detetiveLinha2++;
					detetiveLinha3++;
					detetiveLinha4++;
					cenario[detetiveLinha1][detetiveColuna1] = 2;
					cenario[detetiveLinha2][detetiveColuna2] = 2;
					cenario[detetiveLinha3][detetiveColuna3] = 2;
					cenario[detetiveLinha4][detetiveColuna4] = 2;
				}
			}
			for (int i = 0; i < 22; i++) {
				for (int j = 0; j < 34; j++) {
					printf("%i", cenario[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}

		//--COLISÕES--//

		//colisão do detetive com a tela
		if (detetiveRect.x < 0)
		{
			detetiveRect.x = 0;
		}
		else if (detetiveRect.x > SCREEN_WIDTH - detetiveRect.w)
		{
			detetiveRect.x = SCREEN_WIDTH - detetiveRect.w;
		}
		if (detetiveRect.y < 0)
		{
			detetiveRect.y = 0;
		}
		else if (detetiveRect.y > SCREEN_HEIGHT - detetiveRect.h)
		{
			detetiveRect.y = SCREEN_HEIGHT - detetiveRect.h;
		}

		//--------renderização---------//
		//----------------------------//

		//limpa a renderização
		SDL_RenderClear(window_Renderer);

		//renderiza a textura na tela
		coloca_fundo_preto(window_Renderer);
		SDL_RenderCopy(window_Renderer, gTexture, NULL, &cenario_Rect);

		if (esq)
		{
			switch (frameDetetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive2, NULL, &detetiveRect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive3, NULL, &detetiveRect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive4, NULL, &detetiveRect);
				break;
			case 3:
				SDL_RenderCopy(window_Renderer, detetive3, NULL, &detetiveRect);
				break;
			}
		}
		else if (dir)
		{
			switch (frameDetetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive5, NULL, &detetiveRect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive6, NULL, &detetiveRect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive7, NULL, &detetiveRect);
				break;
			case 3:
				SDL_RenderCopy(window_Renderer, detetive6, NULL, &detetiveRect);
				break;
			}
		}
		else if (cima)
		{
			switch (frameDetetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive9, NULL, &detetiveRect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive8, NULL, &detetiveRect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive10, NULL, &detetiveRect);
				break;
			case 3:
				SDL_RenderCopy(window_Renderer, detetive8, NULL, &detetiveRect);
				break;
			}
		}
		else if (baixo)
		{
			switch (frameDetetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive11, NULL, &detetiveRect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive12, NULL, &detetiveRect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive11, NULL, &detetiveRect);
				break;
			case 3:
				SDL_RenderCopy(window_Renderer, detetive13, NULL, &detetiveRect);
				break;
			}
		}
		else
		{
			if (detetiveLado == 4)
				SDL_RenderCopy(window_Renderer, detetive11, NULL, &detetiveRect);
			if (detetiveLado == 3)
				SDL_RenderCopy(window_Renderer, detetive8, NULL, &detetiveRect);
			if (detetiveLado == 2)
				SDL_RenderCopy(window_Renderer, detetive6, NULL, &detetiveRect);
			if (detetiveLado == 1)
				SDL_RenderCopy(window_Renderer, detetive3, NULL, &detetiveRect);
		}

		if (chatBox == true)
		{
			if (cenario[8][0] == 2 && cenario[8][1] == 2)
				SDL_RenderCopy(window_Renderer, pista1, NULL, &textoRect);
			else if (cenario[18][12] == 2)
				SDL_RenderCopy(window_Renderer, pista2, NULL, &textoRect);
			else if (cenario[12][30] == 2)
				SDL_RenderCopy(window_Renderer, pista3, NULL, &textoRect);
			else if (cenario[5][12] == 2)
				SDL_RenderCopy(window_Renderer, pista4, NULL, &textoRect);
			else if (cenario[4][25] == 2 && cenario[4][26] == 2)
				SDL_RenderCopy(window_Renderer, caixa, NULL, &textoRect);
			else if (cenario[7][13] == 2 && cenario[7][14] == 2 && chave1 == 3 && chave4 == 3 && bau == 3)
				SDL_RenderCopy(window_Renderer, bauAberto, NULL, &textoRect);
			if ((cenario[7][13] == 2 && cenario[7][14] == 2) && cartaDeAmor == 2 && cartaLida == true)
			{
				SDL_RenderCopy(window_Renderer, carta, NULL, &cartaRect);
			}
		}

		for (int i = 0; i < 5; i++)
		{
			switch (i)
			{
			case 0:
				if (chave1 != 0)
					SDL_RenderCopy(window_Renderer, miniChave1, NULL, &itensRect[i]);
				break;
			case 1:
				if (chave2 != 0)
					SDL_RenderCopy(window_Renderer, miniChave2, NULL, &itensRect[i]);
				break;
			case 2:
				if (chave3 != 0)
					SDL_RenderCopy(window_Renderer, miniChave3, NULL, &itensRect[i]);
				break;
			case 3:
				if (chave4 != 0)
					SDL_RenderCopy(window_Renderer, miniChave4, NULL, &itensRect[i]);
				break;
			case 4:
				if (bau != 0)
					SDL_RenderCopy(window_Renderer, miniBau, NULL, &itensRect[i]);
				break;
			}
		}
		//atualiza a renderização
		SDL_RenderPresent(window_Renderer);

		frameDetetive++;
		if (frameDetetive == 4)
			frameDetetive = 0;

		SDL_Delay(50);
	}

	// Finalização do cenario 3

	*cenarios_Completos = 3;

	SDL_DestroyTexture(gTexture);
	Mix_HaltMusic();

} // Fim da função cenario_3()

void cenario_4(SDL_Renderer* window_Renderer, SDL_Surface* window_Surface, SDL_Rect* main_Rect, bool som_Ligado, int* cenarios_Completos)
{
	int largura_tela = 1280;
	int altura_tela = 720;

	// SDL_Texture* pagina_Resolvida_Texture = load_texture("imagens/Pagina_resolvida.png", window_Renderer);
	
	// SDL_RenderCopy(window_Renderer, pagina_Resolvida_Texture, NULL, NULL);

	bool cenario_Completo = false;;

	bool fragmento1 = true;
	bool fragmento2 = true;
	bool fragmento3 = true;
	bool fragmento4 = true;
	bool habilitar_puzzle = false;

	int contador_frag = 0;

	//load_cenario(&contador_frag, &fragmento1, &fragmento2, &fragmento3, &fragmento4, &habilitar_puzzle);

	TTF_Font* fonte = TTF_OpenFont("Recursos/Fonte/Pacifico.ttf", 24);

	//Sound Effects
	Mix_Chunk* passo_1 = Mix_LoadWAV("Recursos/Audios/Passo 1.wav");
	Mix_Chunk* passo_2 = Mix_LoadWAV("Recursos/Audios/Passo 2.wav");
	Mix_Chunk* passo_3 = Mix_LoadWAV("Recursos/Audios/Passo 3.wav");
	//= = = = = = = = = = = =\\

	//= = = = = = = = = = = = Som na Caixa = = = = = = = = = = =\\

	Mix_Music* musica_jogo = Mix_LoadMUS("Recursos/Audios/Som dos Cravos.wav");

	if (som_Ligado)
	{
		musica(musica_jogo, 1);
	}
	//= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\\

	//Verificador de continuidade do jogo
	bool rodar = true;

	//Evento do Jogo
	SDL_Event jogo;

	//= = = = = = = = = Retangulos de Colisao = = = = = = = = = = =\\

	SDL_Rect detetive = { 250, 140, 70, 60 };
	SDL_Rect livro = { (52.44 / 100) * largura_tela, (44.1 / 100) * altura_tela, (4.3 / 100) * largura_tela,(8.8 / 100) * altura_tela };
	SDL_Rect mostrar_texto = { (10.0 / 100) * largura_tela, (75.4 / 100) * altura_tela, (85.0 / 100) * largura_tela, (20.0 / 100) * altura_tela };
	SDL_Rect saida = { 250, 140, 70, 60 };

	SDL_Rect pagina1 = { 0, (29.4 / 100) * altura_tela, 40, 40 };
	SDL_Rect pagina2 = { (63.47 / 100) * largura_tela, (67.64 / 100) * altura_tela, 40, 40 };
	SDL_Rect pagina3 = { (90.82 / 100) * largura_tela, (25.0 / 100) * altura_tela,40, 40 };
	SDL_Rect pagina4 = { (31.25 / 100) * largura_tela, (82.35 / 100) * altura_tela, 40, 40 };

	SDL_Rect colisao_estante1 = { (80.0 / 100) * largura_tela, (16.2 / 100) * altura_tela, (19.5 / 100) * largura_tela, (0.7 / 100) * altura_tela };
	SDL_Rect colisao_estante2 = { (80.0 / 100) * largura_tela, (42.6 / 100) * altura_tela, (19.5 / 100) * largura_tela, (11.2 / 100) * altura_tela };
	SDL_Rect colisao_mesa = { (54.1 / 100) * largura_tela, (35.3 / 100) * altura_tela, (9.76 / 100) * largura_tela, (30.9 / 100) * altura_tela };
	SDL_Rect colisao_parede = { (20.4 / 100) * largura_tela, (11.2 / 100) * altura_tela, (59.5 / 100) * largura_tela, (0.15 / 100) * altura_tela };
	SDL_Rect colisao_escada = { 0, 0, 18.5 / 100 * largura_tela, 23.5 / 100 * altura_tela };
	//= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\\

	SDL_Rect Clipes[4];
	Clipes[0] = { 0, 0, 25, 20 };
	Clipes[1] = { 24, 0, 25, 20 };
	Clipes[2] = { 0, 19, 25, 20 };
	Clipes[3] = { 24, 19, 25, 20 };


	//Variaveis para contar o sprite\\

	int contador_cima = 0;
	int contador_baixo = 0;
	int contador_esq = 0;
	int contador_dir = 0;
	//= = = = = = = = = = = = = = = = =\\

	SDL_Texture* movDetetive = NULL;

	SDL_Texture* textura = load_texture("Recursos/Imagens/CENARIO.png", window_Renderer);
	
	SDL_RenderClear(window_Renderer);

	SDL_RenderCopy(window_Renderer, textura, NULL, NULL);

	textura = load_texture("Recursos/Imagens/Objetos/Livro_Pesquisa_0.png", window_Renderer);

	SDL_RenderCopy(window_Renderer, textura, NULL, &livro);

	textura = load_texture("Recursos/Imagens/Objetos/Pagina_puzzle.png", window_Renderer);

	if (fragmento1)
	{
		SDL_RenderCopy(window_Renderer, textura, &Clipes[0], &pagina1);
	}
	if (fragmento2)
	{
		SDL_RenderCopy(window_Renderer, textura, &Clipes[1], &pagina2);
	}
	if (fragmento3)
	{
		SDL_RenderCopy(window_Renderer, textura, &Clipes[2], &pagina3);
	}
	if (fragmento4)
	{
		SDL_RenderCopy(window_Renderer, textura, &Clipes[3], &pagina4);
	}

	if (!(fragmento1 || fragmento2 || fragmento3 || fragmento4))
	{
		texto(7, NULL, textura, mostrar_texto, fonte, window_Renderer);
	}
	else
	{
		texto(6, NULL, textura, mostrar_texto, fonte, window_Renderer);
	}

	SDL_DestroyTexture(textura);

	SDL_RenderPresent(window_Renderer);

	//Variavel do caminho das imagens para passar na função carregar_midia()
	const char* caminho = "Recursos/Imagens/moviBaixo/detFrt1.png";

	//Indicador da Ultima tecla de movimentação pressionada
	int tecla = 0;

	//Verificador de Colisões
	bool colisao = false;
	bool colisao_livro = false;

	//Indica qual sprite não deve ser alterado
	int alterar = 0;

	int contador_passos = 0;

	//Loop da fase
	while (rodar)
	{
		//Loop da Captura de eventos
		while (SDL_PollEvent(&jogo) != 0)
		{
			//Clicar no X da janela fecha o jogo
			if (jogo.type == SDL_QUIT)
			{
				rodar = false;
			}
			//Pressionar algumas teclas faz alguma coisa
			else if (jogo.type == SDL_KEYDOWN)
			{
				alterar = 0;

				textura = load_texture("Recursos/Imagens/CENARIO.png", window_Renderer);

				SDL_RenderClear(window_Renderer);

				SDL_RenderCopy(window_Renderer, textura, NULL, NULL);

				SDL_DestroyTexture(textura);

				colisao_livro = SDL_HasIntersection(&detetive, &livro);

				if (!colisao_livro)
				{
					textura = load_texture("Recursos/Imagens/Objetos/Livro_Pesquisa_0.png", window_Renderer);
				}
				else
				{
					textura = load_texture("Recursos/Imagens/Objetos/Livro_Pesquisa.png", window_Renderer);
				}

				SDL_RenderCopy(window_Renderer, textura, NULL, &livro);

				SDL_DestroyTexture(textura);

				textura = load_texture("Recursos/Imagens/Objetos/Pag_destaque.png", window_Renderer);

				if (SDL_HasIntersection(&detetive, &pagina1) && fragmento1)
				{
					SDL_RenderCopy(window_Renderer, textura, &Clipes[0], &pagina1);

					alterar = 1;
				}
				else if (SDL_HasIntersection(&detetive, &pagina2) && fragmento2)
				{
					SDL_RenderCopy(window_Renderer, textura, &Clipes[1], &pagina2);

					alterar = 2;
				}
				else if (SDL_HasIntersection(&detetive, &pagina3) && fragmento3)
				{
					SDL_RenderCopy(window_Renderer, textura, &Clipes[2], &pagina3);

					alterar = 3;
				}
				else if (SDL_HasIntersection(&detetive, &pagina4) && fragmento4)
				{
					SDL_RenderCopy(window_Renderer, textura, &Clipes[3], &pagina4);

					alterar = 4;
				}

				SDL_DestroyTexture(textura);

				textura = load_texture("Recursos/Imagens/Objetos/Pagina_puzzle.png", window_Renderer);

				if (alterar == 1)
				{
					if (fragmento2)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[1], &pagina2);
					}
					if (fragmento3)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[2], &pagina3);
					}
					if (fragmento4)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[3], &pagina4);
					}
				}
				else if (alterar == 2)
				{
					if (fragmento1)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[0], &pagina1);
					}
					if (fragmento3)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[2], &pagina3);
					}
					if (fragmento4)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[3], &pagina4);
					}
				}
				else if (alterar == 3)
				{
					if (fragmento1)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[0], &pagina1);
					}
					if (fragmento2)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[1], &pagina2);
					}
					if (fragmento4)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[3], &pagina4);
					}
				}
				else if (alterar == 4)
				{
					if (fragmento1)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[0], &pagina1);
					}
					if (fragmento2)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[1], &pagina2);
					}
					if (fragmento3)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[2], &pagina3);
					}
				}
				else
				{
					if (fragmento1)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[0], &pagina1);
					}
					if (fragmento2)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[1], &pagina2);
					}
					if (fragmento3)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[2], &pagina3);
					}
					if (fragmento4)
					{
						SDL_RenderCopy(window_Renderer, textura, &Clipes[3], &pagina4);
					}
				}

				SDL_DestroyTexture(textura);

				switch (jogo.key.keysym.sym)
				{
					//Move Jackey Para Cima
				case SDLK_w:
				{
					if (tecla != 1)
					{
						tecla = 1;
					}

					if (contador_cima == 1)
					{
						caminho = "Recursos/Imagens/moviCima/detCostas1.png";
					}
					else if (contador_cima == 2)
					{
						caminho = "Recursos/Imagens/moviCima/detCostas2.png";
					}
					else if (contador_cima == 3)
					{
						caminho = "Recursos/Imagens/moviCima/detCostas3.png";
					}
					else if (contador_cima == 4)
					{
						caminho = "Recursos/Imagens/moviCima/detCostas4.png";
						contador_cima = 0;
					}

					mov_detetive(&contador_cima, caminho, movDetetive, detetive, window_Renderer);

					contador_baixo = 1;

					contador_dir = 1;

					contador_esq = 1;

					colisao = SDL_HasIntersection(&detetive, &colisao_mesa) || SDL_HasIntersection(&detetive, &colisao_estante1) || SDL_HasIntersection(&detetive, &colisao_estante2) || SDL_HasIntersection(&detetive, &colisao_parede) || SDL_HasIntersection(&detetive, &colisao_escada);

					if (detetive.y - 10 > 0 && !colisao)
					{
						detetive.y -= 10;
					}

					colisao = SDL_HasIntersection(&detetive, &colisao_mesa) || SDL_HasIntersection(&detetive, &colisao_estante1) || SDL_HasIntersection(&detetive, &colisao_estante2) || SDL_HasIntersection(&detetive, &colisao_parede) || SDL_HasIntersection(&detetive, &colisao_escada);

					if (colisao)
					{
						detetive.y += 10;
					}
					if (som_Ligado)
					{
						som_passos(passo_1, passo_2, passo_3, &contador_passos);
					}

					break;
				}
				//Move Jackey Para Esquerda
				case SDLK_a:
				{
					if (tecla != 2)
					{
						tecla = 2;
					}

					if (contador_esq == 1)
					{
						caminho = "Recursos/Imagens/moviEsq/detEsq1.png";
					}
					else if (contador_esq == 2)
					{
						caminho = "Recursos/Imagens/moviEsq/detEsq2.png";
					}
					else if (contador_esq == 3)
					{
						caminho = "Recursos/Imagens/moviEsq/detEsq3.png";
					}
					else if (contador_esq == 4)
					{
						caminho = "Recursos/Imagens/moviEsq/detEsq4.png";
						contador_esq = 0;
					}

					mov_detetive(&contador_esq, caminho, movDetetive, detetive, window_Renderer);

					contador_baixo = 1;

					contador_dir = 1;

					contador_cima = 1;

					colisao = SDL_HasIntersection(&detetive, &colisao_mesa) || SDL_HasIntersection(&detetive, &colisao_estante1) || SDL_HasIntersection(&detetive, &colisao_estante2) || SDL_HasIntersection(&detetive, &colisao_parede) || SDL_HasIntersection(&detetive, &colisao_escada);

					if (detetive.x - 10 > 0 && !colisao)
					{
						detetive.x -= 10;
					}

					colisao = SDL_HasIntersection(&detetive, &colisao_mesa) || SDL_HasIntersection(&detetive, &colisao_estante1) || SDL_HasIntersection(&detetive, &colisao_estante2) || SDL_HasIntersection(&detetive, &colisao_parede) || SDL_HasIntersection(&detetive, &colisao_escada);

					if (colisao)
					{
						detetive.x += 10;
					}

					if (som_Ligado)
					{
						som_passos(passo_1, passo_2, passo_3, &contador_passos);
					}

					break;
				}
				//Move Jackey Para Baixo
				case SDLK_s:
				{
					if (tecla != 3)
					{
						tecla = 3;
					}

					if (contador_baixo == 1)
					{
						caminho = "Recursos/Imagens/moviBaixo/detFrt1.png";
					}
					else if (contador_baixo == 2)
					{
						caminho = "Recursos/Imagens/moviBaixo/detFrt2.png";
					}
					else if (contador_baixo == 3)
					{
						caminho = "Recursos/Imagens/moviBaixo/detFrt3.png";
					}
					else if (contador_baixo == 4)
					{
						caminho = "Recursos/Imagens/moviBaixo/detFrt4.png";
						contador_baixo = 0;
					}

					mov_detetive(&contador_baixo, caminho, movDetetive, detetive, window_Renderer);

					contador_cima = 1;

					contador_dir = 1;

					contador_esq = 1;

					colisao = SDL_HasIntersection(&detetive, &colisao_mesa) || SDL_HasIntersection(&detetive, &colisao_estante1) || SDL_HasIntersection(&detetive, &colisao_estante2) || SDL_HasIntersection(&detetive, &colisao_parede) || SDL_HasIntersection(&detetive, &colisao_escada);

					if ((detetive.y + 10 + detetive.h) < altura_tela && !colisao)
					{
						detetive.y += 10;
					}

					colisao = SDL_HasIntersection(&detetive, &colisao_mesa) || SDL_HasIntersection(&detetive, &colisao_estante1) || SDL_HasIntersection(&detetive, &colisao_estante2) || SDL_HasIntersection(&detetive, &colisao_parede) || SDL_HasIntersection(&detetive, &colisao_escada);

					if (colisao)
					{
						detetive.y -= 10;
					}

					if (som_Ligado)
					{
						som_passos(passo_1, passo_2, passo_3, &contador_passos);
					}
					break;
				}
				//Move Jackey Para Direita
				case SDLK_d:
				{
					if (tecla != 4)
					{
						tecla = 4;
					}

					if (contador_dir == 1)
					{
						caminho = "Recursos/Imagens/moviDir/detDir1.png";
					}
					else if (contador_dir == 2)
					{
						caminho = "Recursos/Imagens/moviDir/detDir2.png";
					}
					else if (contador_dir == 3)
					{
						caminho = "Recursos/Imagens/moviDir/detDir3.png";
					}
					else if (contador_dir == 4)
					{
						caminho = "Recursos/Imagens/moviDir/detDir4.png";
						contador_dir = 0;
					}

					mov_detetive(&contador_dir, caminho, movDetetive, detetive, window_Renderer);

					contador_baixo = 1;

					contador_cima = 1;

					contador_esq = 1;

					colisao = SDL_HasIntersection(&detetive, &colisao_mesa) || SDL_HasIntersection(&detetive, &colisao_estante1) || SDL_HasIntersection(&detetive, &colisao_estante2) || SDL_HasIntersection(&detetive, &colisao_parede) || SDL_HasIntersection(&detetive, &colisao_escada);

					if ((detetive.x + 10 + detetive.w) < largura_tela && !colisao)
					{
						detetive.x += 10;
					}

					colisao = SDL_HasIntersection(&detetive, &colisao_mesa) || SDL_HasIntersection(&detetive, &colisao_estante1) || SDL_HasIntersection(&detetive, &colisao_estante2) || SDL_HasIntersection(&detetive, &colisao_parede) || SDL_HasIntersection(&detetive, &colisao_escada);

					if (colisao)
					{
						detetive.x -= 10;
					}
					if (som_Ligado)
					{
						som_passos(passo_1, passo_2, passo_3, &contador_passos);
					}
					break;
				}
				case SDLK_e:
				{
					manter_detetive(&contador_baixo, &contador_cima, &contador_dir, &contador_esq, &tecla, &detetive, movDetetive, caminho, window_Renderer);

					if (contador_frag < 5)
					{

						if (colisao_livro)
						{
							if (contador_frag == 4)
							{
								contador_frag++;
								cenario_Completo = true;
							}
							habilitar_puzzle = true;
						}
						else if (SDL_HasIntersection(&detetive, &pagina1) && fragmento1)
						{
							fragmento1 = false;
							contador_frag++;
						}
						else if (SDL_HasIntersection(&detetive, &pagina2) && fragmento2)
						{
							fragmento2 = false;
							contador_frag++;
						}
						else if (SDL_HasIntersection(&detetive, &pagina3) && fragmento3)
						{
							fragmento3 = false;
							contador_frag++;
						}
						else if (SDL_HasIntersection(&detetive, &pagina4) && fragmento4)
						{
							fragmento4 = false;
							contador_frag++;
						}

						texto(contador_frag, habilitar_puzzle, textura, mostrar_texto, fonte, window_Renderer);
					}
					else
					{
						texto(7, NULL, textura, mostrar_texto, fonte, window_Renderer);
					}

					SDL_RenderPresent(window_Renderer);
					break;
				}
				case SDLK_k:
				{
					manter_detetive(&contador_baixo, &contador_cima, &contador_dir, &contador_esq, &tecla, &detetive, movDetetive, caminho, window_Renderer);

					if (SDL_HasIntersection(&detetive, &saida) && cenario_Completo)
					{
						rodar = false;
					}
					break;
				}
				case SDLK_f:
				{
					manter_detetive(&contador_baixo, &contador_cima, &contador_dir, &contador_esq, &tecla, &detetive, movDetetive, caminho, window_Renderer);

					if (contador_frag == 5)
					{
						// pagina_Resolvida_Texture = load_texture("Recursos/Imagens/Objetos/Pagina_resolvida.png", window_Renderer);
						//SDL_RenderCopy(window_Renderer, pagina_Resolvida_Texture, NULL, NULL);
						// SDL_DestroyTexture(textura);
						// SDL_Delay(5000);
					}

					//break;
				}
				default:
				{
					manter_detetive(&contador_baixo, &contador_cima, &contador_dir, &contador_esq, &tecla, &detetive, movDetetive, caminho, window_Renderer);
				}
				}
			}
		}

		SDL_RenderPresent(window_Renderer);
	
	 } // Fim do while(rodar)

	TTF_CloseFont(fonte);
	Mix_HaltMusic();

	// SDL_RenderClear(window_Renderer);
	// SDL_RenderCopy(window_Renderer, pagina_Resolvida_Texture, NULL, NULL);

	*cenarios_Completos = 4;

} // Fim da função cenario_4()

// --------------------------------------------------------------------------------------- //

bool mini_game(SDL_Renderer* window_Renderer, SDL_Surface* window_Surface, bool* som_Ligado, bool* vivo)
{
	const int velAsssassino = 75; //delay para retardar o movimento do assassino
	const int quantBlocos = 20; //quantidade de blocos a serem criados

	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;

	SDL_Texture* detetive_Costa_Texture = NULL;

	SDL_Texture* detetive_Lado_Esquerdo_1_Texture = NULL;
	SDL_Texture* detetive_Lado_Esquerdo_2_Texture = NULL;
	SDL_Texture* detetive_Lado_Esquerdo_3_Texture = NULL;

	SDL_Texture* detetive_Lado_Direito_1_Texture = NULL;
	SDL_Texture* detetive_Lado_Direito_2_Texture = NULL;
	SDL_Texture* detetive_Lado_Direito_3_Texture = NULL;

	SDL_Texture* assassino1 = NULL;
	SDL_Texture* assassino2 = NULL;
	SDL_Texture* assassino3 = NULL;
	SDL_Texture* obst = NULL;
	SDL_Texture* barraDeLife1 = NULL;
	SDL_Texture* barraDeLife2 = NULL;
	SDL_Texture* barraDeLife3 = NULL;
	SDL_Texture* barraDeLife4 = NULL;
	SDL_Texture* barraDeLife5 = NULL;
	SDL_Texture* projetil = NULL;


	SDL_Texture* background_Texture = load_texture("imagens/background.png", window_Renderer);
	detetive_Costa_Texture = load_texture("imagens/detetive costa 1.png", window_Renderer);

	detetive_Lado_Direito_1_Texture = load_texture("imagens/detetive lado dir 1.png", window_Renderer);
	detetive_Lado_Direito_2_Texture = load_texture("imagens/detetive lado dir 2.png", window_Renderer);
	detetive_Lado_Direito_3_Texture = load_texture("imagens/detetive lado dir 3.png", window_Renderer);

	detetive_Lado_Esquerdo_1_Texture = load_texture("imagens/detetive lado esq 1.png", window_Renderer);
	detetive_Lado_Esquerdo_2_Texture = load_texture("imagens/detetive lado esq 2.png", window_Renderer);
	detetive_Lado_Esquerdo_3_Texture = load_texture("imagens/detetive lado esq 3.png", window_Renderer);

	assassino1 = load_texture("imagens/assassino1.png", window_Renderer);
	assassino2 = load_texture("imagens/assassino2.png", window_Renderer);
	assassino3 = load_texture("imagens/assassino3.png", window_Renderer);

	obst = load_texture("imagens/obstaculo.png", window_Renderer);
	barraDeLife1 = load_texture("imagens/barradelife1.png", window_Renderer);
	barraDeLife2 = load_texture("imagens/barradelife2.png", window_Renderer);
	barraDeLife3 = load_texture("imagens/barradelife3.png", window_Renderer);
	barraDeLife4 = load_texture("imagens/barradelife4.png", window_Renderer);
	barraDeLife5 = load_texture("imagens/barradelife5.png", window_Renderer);
	projetil = load_texture("imagens/tiro.png", window_Renderer);


	//contadores de vida
	int vidaDetetive = 4;
	int vidaAssassino = 4;

	//booleanas de movimento
	bool esq = false;
	bool dir = false;
	bool atirar = false;

	SDL_bool colIniBloq[quantBlocos];
	SDL_bool colProjIni;

	//contadores de frames
	int frameAtual = 0;
	int frameDetetive = 0;
	int qtdFrame = 3;

	bool tem_um_tiro = false;

	//randoniza a posição X do assassino
	srand(time(NULL));

	//função booleana de execução do loop e criação da variavel atribuida a eventos
	bool executando = true;
	SDL_Event click;

	//--Area de criação de retangulos :D --//

	SDL_Rect detetiveRect;
	detetiveRect.x = SCREEN_WIDTH / 2 - 25;
	detetiveRect.y = SCREEN_HEIGHT - 50;
	detetiveRect.w = 50;
	detetiveRect.h = 50;

	SDL_Rect assassinoRect;
	assassinoRect.x = rand() % 1029 - rand() % 1029;
	while (assassinoRect.x < 0)
	{
		assassinoRect.x = rand() % 1029 - rand() % 1029;
	}
	assassinoRect.y = 0;
	assassinoRect.w = 50;
	assassinoRect.h = 50;

	float velMovAssassinoX = 8;
	float velMovAssassinoY = 8;


	bool blocoViVo[quantBlocos];
	for (int i = 0; i < quantBlocos; i++)
	{
		blocoViVo[i] = true;
	}
	SDL_Rect obstaculosRect[quantBlocos];
	for (int i = 0, x = 4, y = 150; i < quantBlocos; i++, x += 250)
	{
		if (blocoViVo[i] == true)
		{
			if (x > 1010)
			{
				x = 4;
				y += 150;
			}
			obstaculosRect[i].x = x;
			obstaculosRect[i].y = y;
			obstaculosRect[i].w = 60;
			obstaculosRect[i].h = 20;
		}
	}


	SDL_Rect lifeDetetiveRect;
	lifeDetetiveRect.x = 0;
	lifeDetetiveRect.y = 0;
	lifeDetetiveRect.w = 200;
	lifeDetetiveRect.h = 60;

	SDL_Rect lifeAssassinoRect;
	lifeAssassinoRect.x = 880;
	lifeAssassinoRect.y = 0;
	lifeAssassinoRect.w = 200;
	lifeAssassinoRect.h = 60;

	SDL_Rect projetilRect;
	SDL_Rect projetilRectCopia;
	bool projetilVida = true;

	float velProjetil = 20;


	//--fim da área de criação de retângulos--//

	//loop principal do jogo
	while (executando)
	{

		//eventos de comando do teclado/mouse
		while (SDL_PollEvent(&click))
		{
			//fechando a janela com ESC ou clique no X
			if (click.type == SDL_QUIT)
			{
				executando = false;
			}

			switch (click.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				executando = false;
			}

			if (click.type == SDL_KEYDOWN)
			{
				if (click.key.keysym.sym == SDLK_a)
				{
					esq = true;
				}
				else if (click.key.keysym.sym == SDLK_d)
				{
					dir = true;
				}
				else if (click.key.keysym.sym == SDLK_k)
				{
					if (projetilVida && !tem_um_tiro)
					{
						projetilRect.x = detetiveRect.x;
						projetilRect.y = SCREEN_HEIGHT - 50;
						projetilRect.w = 10;
						projetilRect.h = 20;

						projetilRectCopia = projetilRect;
					}

					tem_um_tiro = true;
					atirar = true;
				}
			}
			else if (click.type == SDL_KEYUP)
				if (click.key.keysym.sym == SDLK_a)
				{
					esq = false;
				}
				else if (click.key.keysym.sym == SDLK_d)
				{
					dir = false;
				}
		}

		//---------------lógica----------------------//
		//------------------------------------------//

		//---DETETIVE---//

		//movimento do detetive
		if (esq == true)
		{
			detetiveRect.x -= 24;
		}
		else if (dir == true)
		{
			detetiveRect.x += 24;
		}

		//colisão do detetive com a tela
		if (detetiveRect.x < 0)
		{
			detetiveRect.x = 0;
		}
		else if (detetiveRect.x > SCREEN_WIDTH - detetiveRect.w)
		{
			detetiveRect.x = SCREEN_WIDTH - detetiveRect.w;
		}

		//--ASSASSINO--//

		//movimento do inimigo
		assassinoRect.x += velMovAssassinoX;
		assassinoRect.y += velMovAssassinoY;

		//colisão do inimigo com a tela
		if (assassinoRect.x < 0)
		{
			assassinoRect.x = 0;
			if (assassinoRect.x == 0)
			{
				velMovAssassinoX = -velMovAssassinoX;
			}
		}
		if (assassinoRect.x > SCREEN_WIDTH - assassinoRect.w)
		{
			assassinoRect.x = SCREEN_WIDTH - assassinoRect.w;
			if (assassinoRect.x == SCREEN_WIDTH - assassinoRect.w)
			{
				velMovAssassinoX = -velMovAssassinoX;
			}
		}
		if (assassinoRect.y < 0)
		{
			assassinoRect.y = 0;
			if (assassinoRect.y == 0)
			{
				velMovAssassinoY = -velMovAssassinoY;
			}
		}
		if (assassinoRect.y > SCREEN_HEIGHT - assassinoRect.h)
		{
			assassinoRect.y = SCREEN_HEIGHT - assassinoRect.h;
			if (assassinoRect.y == SCREEN_HEIGHT - assassinoRect.h)
			{
				velMovAssassinoY = -velMovAssassinoY;
			}
		}

		//--PROJETIL--//

		// posição do projetil
		if (atirar == false)
		{
			projetilRect.x = detetiveRect.x;
		}

		//movimento do projetil

		if (atirar == true)
		{
			if (projetilRect.y > 0)
			{
				projetilRect.y = projetilRect.y - velProjetil;
				projetilRectCopia.y = projetilRect.y - velProjetil;
			}
			else if (projetilRect.y <= 0)
			{
				projetilRect.y = SCREEN_HEIGHT - 50;
				projetilRectCopia.y = SCREEN_HEIGHT - 50;
				projetilVida = false;
				atirar = false;
			}
		}


		//--COLISÕES--//

		//colisão do inimigo com o detetive
		SDL_bool colIniDet = SDL_HasIntersection(&assassinoRect, &detetiveRect);

		if (colIniDet)
		{
			velMovAssassinoX = velMovAssassinoX;
			velMovAssassinoY = -velMovAssassinoY;

			vidaDetetive--;

			if (vidaDetetive == 0)
			{
				executando = false;

				*vivo = false;
			}
		}

		//colisão do inimigo com os obstaculos

		for (int i = 0; i < quantBlocos; i++)
		{
			colIniBloq[i] = (SDL_bool)true;
		}

		for (int i = 0; i < quantBlocos; i++)
		{
			colIniBloq[i] = SDL_HasIntersection(&assassinoRect, &obstaculosRect[i]);
		}

		for (int i = 0; i < quantBlocos; i++)
		{
			if (colIniBloq[i] == true)
			{
				if (blocoViVo[i] == true)
				{
					velMovAssassinoX = velMovAssassinoX * 1.1;
					velMovAssassinoY = -velMovAssassinoY * 1.1;

					blocoViVo[i] = false;
				}
			}
		}

		//colisão projetil com inimigo

		colProjIni = SDL_HasIntersection(&projetilRect, &assassinoRect);

		if (colProjIni)
		{
			projetilRect.y = SCREEN_HEIGHT - 50;

			atirar = false;
			tem_um_tiro = false;

			vidaAssassino--;
			if (vidaAssassino <= 0)
			{
				vidaAssassino = 0;
				executando = false;
			}
		}


		//--------renderização---------//
		//----------------------------//

		//limpa a renderização
		SDL_RenderClear(window_Renderer);

		//renderiza a textura na tela
		SDL_RenderCopy(window_Renderer, background_Texture, NULL, NULL);


		if (esq)
		{
			switch (frameDetetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Esquerdo_1_Texture, NULL, &detetiveRect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Esquerdo_2_Texture, NULL, &detetiveRect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Esquerdo_3_Texture, NULL, &detetiveRect);
				break;
			}
		}
		else if (dir)
		{
			switch (frameDetetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Direito_1_Texture, NULL, &detetiveRect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Direito_2_Texture, NULL, &detetiveRect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Direito_3_Texture, NULL, &detetiveRect);
				break;
			}
		}
		else
		{
			SDL_RenderCopy(window_Renderer, detetive_Costa_Texture, NULL, &detetiveRect);
		}

		switch (frameAtual)
		{
		case 0:
			SDL_RenderCopy(window_Renderer, assassino1, NULL, &assassinoRect);
			break;
		case 1:
			SDL_RenderCopy(window_Renderer, assassino2, NULL, &assassinoRect);
			break;
		case 2:
			SDL_RenderCopy(window_Renderer, assassino3, NULL, &assassinoRect);
			break;
		}

		for (int i = 0; i < quantBlocos; i++)
		{
			if (blocoViVo[i] == true)
			{
				SDL_RenderCopy(window_Renderer, obst, NULL, &obstaculosRect[i]);
			}
		}

		switch (vidaDetetive)
		{
		case 4:
			SDL_RenderCopy(window_Renderer, barraDeLife1, NULL, &lifeDetetiveRect);
			break;
		case 3:
			SDL_RenderCopy(window_Renderer, barraDeLife2, NULL, &lifeDetetiveRect);
			break;
		case 2:
			SDL_RenderCopy(window_Renderer, barraDeLife3, NULL, &lifeDetetiveRect);
			break;
		case 1:
			SDL_RenderCopy(window_Renderer, barraDeLife4, NULL, &lifeDetetiveRect);
			break;
		case 0:
			SDL_RenderCopy(window_Renderer, barraDeLife5, NULL, &lifeDetetiveRect);
			break;
		}

		switch (vidaAssassino)
		{
		case 4:
			SDL_RenderCopy(window_Renderer, barraDeLife1, NULL, &lifeAssassinoRect);
			break;
		case 3:
			SDL_RenderCopy(window_Renderer, barraDeLife2, NULL, &lifeAssassinoRect);
			break;
		case 2:
			SDL_RenderCopy(window_Renderer, barraDeLife3, NULL, &lifeAssassinoRect);
			break;
		case 1:
			SDL_RenderCopy(window_Renderer, barraDeLife4, NULL, &lifeAssassinoRect);
			break;
		case 0:
			SDL_RenderCopy(window_Renderer, barraDeLife5, NULL, &lifeAssassinoRect);
			break;
		}

		if (atirar == true)
		{
			if (projetilVida == true || 1)
			{
				SDL_RenderCopy(window_Renderer, projetil, NULL, &projetilRect);
			}
		}
		else if (atirar == false)
		{
			projetilVida == true;
		}


		//atualiza a renderização
		SDL_RenderPresent(window_Renderer);

		frameAtual++;
		if (frameAtual == 3)
			frameAtual = 0;

		frameDetetive++;
		if (frameDetetive == 3)
			frameDetetive = 0;



		SDL_Delay(velAsssassino);
	}

	// Finalização do mini_game()

	SDL_DestroyTexture(gTexture);
	SDL_DestroyTexture(detetive_Costa_Texture);
	SDL_DestroyTexture(detetive_Lado_Esquerdo_1_Texture);
	SDL_DestroyTexture(detetive_Lado_Esquerdo_2_Texture);
	SDL_DestroyTexture(detetive_Lado_Esquerdo_3_Texture);
	SDL_DestroyTexture(detetive_Lado_Direito_1_Texture);
	SDL_DestroyTexture(detetive_Lado_Direito_2_Texture);
	SDL_DestroyTexture(detetive_Lado_Direito_3_Texture);
	SDL_DestroyTexture(assassino1);
	SDL_DestroyTexture(assassino2);
	SDL_DestroyTexture(assassino3);
	SDL_DestroyTexture(obst);
	SDL_DestroyTexture(barraDeLife1);
	SDL_DestroyTexture(barraDeLife2);
	SDL_DestroyTexture(barraDeLife3);
	SDL_DestroyTexture(barraDeLife4);
	SDL_DestroyTexture(barraDeLife5);
	SDL_DestroyTexture(projetil);

	gTexture = NULL;
	detetive_Costa_Texture = NULL;
	detetive_Lado_Esquerdo_1_Texture = NULL;
	detetive_Lado_Esquerdo_2_Texture = NULL;
	detetive_Lado_Esquerdo_3_Texture = NULL;
	detetive_Lado_Direito_1_Texture = NULL;
	detetive_Lado_Direito_2_Texture = NULL;
	detetive_Lado_Direito_3_Texture = NULL;
	assassino1 = NULL;
	assassino2 = NULL;
	assassino3 = NULL;
	obst = NULL;
	barraDeLife1 = NULL;
	barraDeLife2 = NULL;
	barraDeLife3 = NULL;
	barraDeLife4 = NULL;
	barraDeLife5 = NULL;
	projetil = NULL;

	return *vivo;

} // Fim da função mini_game()

void escolha_cenarios(SDL_Renderer* window_Renderer, SDL_Surface* window_Surface,SDL_Rect* main_Rect , int dificuldade, bool som_Ligado, int* cenarios_Completos, bool* vivo)
{
	// mini_game(window_Renderer, window_Surface, &som_Ligado, vivo);//  <---- eh assim que chama a função do mini jogo
	
	SDL_Texture* cidade_Texture = load_texture("imagens/cidade otimizada.png", window_Renderer);

	SDL_Texture* contorno_Delegacia_Texture = load_texture("imagens/contorno delegacia.png", window_Renderer);
	SDL_Texture* contorno_1_Texture = load_texture("imagens/contorno casa 1.png", window_Renderer);
	SDL_Texture* contorno_2_Texture = load_texture("imagens/contorno casa 2.png", window_Renderer);
	SDL_Texture* contorno_3_Texture = load_texture("imagens/contorno casa 3.png", window_Renderer);
	SDL_Texture* contorno_4_Texture = load_texture("imagens/contorno casa 4.png", window_Renderer);
	
	srand(time(NULL));

	int chance_minigame = 40;

	int lugar = 0; //lugar vai de 0 a 4 // 0 = delegacia // 1 = cenario 1 // 2 = cenario 2 // 3 = cenario 3 // 4 = cenario 4
	bool escolha_Cenarios = true;
	SDL_Event event;


	while (escolha_Cenarios && *vivo)
	{
		SDL_RenderPresent(window_Renderer);
		while (SDL_PollEvent(&event) != 0) // Enquanto existir evento o loop continua
		{
			// Evento: fechar main_Window
			if (event.type == SDL_QUIT)
			{
				escolha_Cenarios = false;
			}
			// Evento: tecla pressionada
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_a:
					if (lugar - 1 < 0)
					{
						lugar = 4;
					}
					else
					{
						lugar--;
					}
					break;

				case SDLK_d:
					if (lugar + 1 > 4)
					{
						lugar = 0;
					}
					else
					{
						lugar++;
					}
					break;
				case SDLK_LEFT:
					if (lugar - 1 < 0)
					{
						lugar = 4;
					}
					else
					{
						lugar--;
					}
					break;

				case SDLK_RIGHT:
					if (lugar + 1 > 4)
					{
						lugar = 0;
					}
					else
					{
						lugar++;
					}
					break;

				case SDLK_RETURN:

					switch (lugar)
					{
					case 0:
						escolha_Cenarios = false;
						break;
					case 1:
						if (*cenarios_Completos == 0)
						{
							chance_minigame = rand() % 100 + dificuldade;
							if (chance_minigame >= 100)
							{
								*vivo = mini_game(window_Renderer, window_Surface, &som_Ligado, vivo);
							}
							if (*vivo)
							{
								cenario_1(window_Renderer, window_Surface, main_Rect, som_Ligado, cenarios_Completos);
							}
						}

						break;
					case 2:
						if (*cenarios_Completos == 1)
						{
							chance_minigame = rand() % 100 + dificuldade;
							if (chance_minigame >= 100)
							{
								*vivo = mini_game(window_Renderer, window_Surface, &som_Ligado, vivo);
							}
							if (*vivo)
							{
								cenario_2(window_Renderer, window_Surface, main_Rect, som_Ligado, cenarios_Completos);
							}
						}
						break;
					case 3:
						if (*cenarios_Completos == 2)
						{
							chance_minigame = rand() % 100 + dificuldade;
							if (chance_minigame >= 100)
							{
								*vivo = mini_game(window_Renderer, window_Surface, &som_Ligado, vivo);
							}
							if (*vivo)
							{
								cenario_3(window_Renderer, window_Surface, main_Rect, som_Ligado, cenarios_Completos);
							}
						}
						

						break;
					case 4:
						if (*cenarios_Completos == 4)
						{
							chance_minigame = rand() % 100 + dificuldade;
							if (chance_minigame >= 100)
							{
								*vivo = mini_game(window_Renderer, window_Surface, &som_Ligado, vivo);
							}
							if (*vivo)
							{
								cenario_4(window_Renderer, window_Surface, main_Rect, som_Ligado, cenarios_Completos);
								// SDL_RenderCopy();
							}
						}
						

						break;
					}
					break;

				case SDLK_SPACE:

					switch (lugar)
					{
					case 0:
						escolha_Cenarios = false;
						break;
					case 1:
						if (*cenarios_Completos == 0)
						{
							chance_minigame = rand() % 100 + dificuldade;
							if (chance_minigame >= 100)
							{
								 *vivo = mini_game(window_Renderer, window_Surface, &som_Ligado, vivo);
							}
							if (*vivo)
							{
								cenario_1(window_Renderer, window_Surface, main_Rect, som_Ligado, cenarios_Completos);
							}
						}

						break;
					case 2:
						if (*cenarios_Completos == 1)
						{
							chance_minigame = rand() % 100 + dificuldade;
							if (chance_minigame >= 100)
							{
								*vivo = mini_game(window_Renderer, window_Surface, &som_Ligado, vivo);
							}
							if (*vivo)
							{
								cenario_2(window_Renderer, window_Surface, main_Rect, som_Ligado, cenarios_Completos);
							}
						}
						break;
					case 3:
						if (*cenarios_Completos == 2)
						{
							chance_minigame = rand() % 100 + dificuldade;
							if (chance_minigame >= 100)
							{
								*vivo = mini_game(window_Renderer, window_Surface, &som_Ligado, vivo);
							}
							if (*vivo)
							{
								cenario_3(window_Renderer, window_Surface, main_Rect, som_Ligado, cenarios_Completos);
							}
						}


						break;
					case 4:
						if (*cenarios_Completos == 3)
						{
							chance_minigame = rand() % 100 + dificuldade;
							if (chance_minigame >= 100)
							{
								*vivo = mini_game(window_Renderer, window_Surface, &som_Ligado, vivo);
							}
							if (*vivo)
							{
								cenario_4(window_Renderer, window_Surface, main_Rect, som_Ligado, cenarios_Completos);
							}
						}
						break;
					}
					break;
				}

			} // Fim do evento de tecla pressionada

		}// Fim do loop de eventos

		SDL_RenderCopy(window_Renderer, cidade_Texture, NULL, NULL);

		if (lugar == 0)
		{
			SDL_RenderCopy(window_Renderer, contorno_Delegacia_Texture, NULL, NULL);
		}
		else if (lugar == 1)
		{
			SDL_RenderCopy(window_Renderer, contorno_1_Texture, NULL, NULL);
		}
		else if (lugar == 2)
		{
			SDL_RenderCopy(window_Renderer, contorno_2_Texture, NULL, NULL);
		}
		else if (lugar == 3)
		{
			SDL_RenderCopy(window_Renderer, contorno_3_Texture, NULL, NULL);
		}
		else if (lugar == 4)
		{
			SDL_RenderCopy(window_Renderer, contorno_4_Texture, NULL, NULL);
		}
		

	}//fim do while(escolha_Cenario) 

	SDL_DestroyTexture(cidade_Texture);

	SDL_DestroyTexture(contorno_Delegacia_Texture);
	SDL_DestroyTexture(contorno_1_Texture);
	SDL_DestroyTexture(contorno_2_Texture);
	SDL_DestroyTexture(contorno_3_Texture);
	SDL_DestroyTexture(contorno_4_Texture);

	cidade_Texture = NULL;

	contorno_Delegacia_Texture = NULL;
	contorno_1_Texture = NULL;
	contorno_2_Texture = NULL;
	contorno_3_Texture = NULL;
	contorno_4_Texture = NULL;

} // Fim da função de escolher cenário

// --------------------------------------------------------------------------------------- //

void cenario_delegacia(SDL_Renderer* window_Renderer, SDL_Surface* window_Surface, SDL_Rect* main_Rect, bool load_game, int dificuldade, bool som_Ligado, int* cenarios_Completos, bool* vivo)
{
	Mix_Music* musica_jogo = Mix_LoadMUS("Recursos/Audios/som delegacia.wav");

	if (som_Ligado)
	{
		musica(musica_jogo, 1);
	}

	coloca_fundo_preto(window_Renderer);

	int cenario_Width = 240;  //15x16
	int cenario_Height = 192; //12x16
	int amplificador = 3;
	int lado = 16;

	SDL_Rect cenario_Rect;
	cenario_Rect.x = 1280 / 2 - cenario_Width / 2 * amplificador;
	cenario_Rect.y = 720 / 2 - cenario_Height / 2 * amplificador;
	cenario_Rect.w = cenario_Width * amplificador;
	cenario_Rect.h = cenario_Height * amplificador;

	SDL_RenderSetViewport(window_Renderer, &cenario_Rect);

	SDL_Rect grid[12][15];

	for (int linha = 0; linha < 12; linha++)
	{
		for (int coluna = 0; coluna < 15; coluna++)
		{
			grid[linha][coluna].x = lado * amplificador * coluna;
			grid[linha][coluna].y = lado * amplificador * linha;
			grid[linha][coluna].w = lado * amplificador;
			grid[linha][coluna].h =	lado * amplificador;
		}
	}

	// ------------------------------- //

	char delegacia_Centro[12][15] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
								      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
								      ' ', ' ', '_', '_', '_', '_', ' ', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
								      ' ', '_', '_', '_', '_', '_', ' ', ' ', ' ', '_', '_', '_', '_', '_', ' ',
								      '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_',
								      ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
								      ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
								      ' ', '_', '_', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
								      ' ', '_', '_', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
								      ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
								      ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ', ' ', ' ',
								      ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
									  
	char delegacia_Direita[12][15] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
									   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
									   ' ', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ', ' ', ' ',
									   ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
									   '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
									   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
									   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
									   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
									   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
									   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
									   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
									   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

	char delegacia_Esquerda[12][15] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
									    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
									    ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', '_', ' ', ' ', ' ', ' ', ' ', ' ',
									    ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
									    ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_',
									    ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
									    ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', '_', ' ', ' ', ' ', '_', '_', ' ',
									    ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
									    ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
									    ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', '_', ' ', ' ', ' ', '_', '_', ' ',
									    ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
										' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

	// ------------------------------- //

	SDL_Texture* background_Texture_Centro = load_texture("imagens/delegacia centro.png", window_Renderer);

	SDL_Texture* background_Texture_Direita = load_texture("imagens/delegacia direita.png", window_Renderer);

	SDL_Texture* background_Texture_Esquerda = load_texture("imagens/delegacia esquerda.png", window_Renderer);


	SDL_Texture* detetive_Costa_1_Texture = load_texture("imagens/detetive costa 1.png", window_Renderer);
	SDL_Texture* detetive_Costa_2_Texture = load_texture("imagens/detetive costa 2.png", window_Renderer);
	SDL_Texture* detetive_Costa_3_Texture = load_texture("imagens/detetive costa 3.png", window_Renderer);

	SDL_Texture* detetive_Frente_1_Texture = load_texture("imagens/detetive frente 1.png", window_Renderer);
	SDL_Texture* detetive_Frente_2_Texture = load_texture("imagens/detetive frente 2.png", window_Renderer);
	SDL_Texture* detetive_Frente_3_Texture = load_texture("imagens/detetive frente 3.png", window_Renderer);

	SDL_Texture* detetive_Lado_Direito_1_Texture = load_texture("imagens/detetive lado dir 1.png", window_Renderer);
	SDL_Texture* detetive_Lado_Direito_2_Texture = load_texture("imagens/detetive lado dir 2.png", window_Renderer);
	SDL_Texture* detetive_Lado_Direito_3_Texture = load_texture("imagens/detetive lado dir 3.png", window_Renderer);

	SDL_Texture* detetive_Lado_Esquerdo_1_Texture = load_texture("imagens/detetive lado esq 1.png", window_Renderer);
	SDL_Texture* detetive_Lado_Esquerdo_2_Texture = load_texture("imagens/detetive lado esq 2.png", window_Renderer);
	SDL_Texture* detetive_Lado_Esquerdo_3_Texture = load_texture("imagens/detetive lado esq 3.png", window_Renderer);
	

	SDL_Texture* assassino_Texture = load_texture("imagens/assassino1.png", window_Renderer);

	SDL_Rect assassino_Rect;
	assassino_Rect.x = grid[8][5].x;
	assassino_Rect.y = grid[8][5].y;
	assassino_Rect.h = 64;
	assassino_Rect.w = 64;
	
	SDL_Texture* npc_Texture = load_texture("imagens/npc.png", window_Renderer);

	SDL_Rect npc_Rect;
	npc_Rect.x = grid[2][7].x -16;
	npc_Rect.y = grid[2][7].y -16;
	npc_Rect.h = 64;
	npc_Rect.w = 64;

	SDL_Texture* planta_Texture = load_texture("imagens/vaso de planta.png", window_Renderer);

	SDL_Rect planta_Direita_Rect; // lugar da planta direita inferior
	planta_Direita_Rect.x = grid[9][13].x;
	planta_Direita_Rect.y = grid[9][13].y;
	planta_Direita_Rect.w = 16 * amplificador;
	planta_Direita_Rect.h = 32 * amplificador;

	SDL_Rect planta_Esquerda_Rect; // lugar da planta da esquerda inferior
	planta_Esquerda_Rect.x = grid[9][1].x;
	planta_Esquerda_Rect.y = grid[9][1].y;
	planta_Esquerda_Rect.w = 16 * amplificador;
	planta_Esquerda_Rect.h = 32 * amplificador;

	SDL_Texture* lixeira_Texture = load_texture("imagens/lixeira.png", window_Renderer);

	SDL_Rect lixeira_Rect; // lugar do lixo
	lixeira_Rect.x = grid[9][12].x;
	lixeira_Rect.y = grid[9][12].y;
	lixeira_Rect.w = 16 * amplificador;
	lixeira_Rect.h = 32 * amplificador;

	SDL_Texture* bancadas_Texture = load_texture("imagens/delegacia esquerda bancadas.png", window_Renderer);

	// ------------------------------- //

	SDL_Rect detetive_Rect;
	detetive_Rect.x = grid[9][7].x -16;
	detetive_Rect.y = grid[9][7].y -16;
	detetive_Rect.w = 64;
	detetive_Rect.h = 64;

	SDL_Rect detetive_Rect_Hitbox = detetive_Rect;
	detetive_Rect_Hitbox.x += detetive_Rect.w/2;
	detetive_Rect_Hitbox.w /= 48;
	detetive_Rect_Hitbox.y += detetive_Rect.h/2;
	detetive_Rect_Hitbox.h /= 48;

	SDL_Texture* box_Texture = load_texture("imagens/chat box.png", window_Renderer);

	SDL_Rect box_Rect;
	box_Rect.x = 0;
	box_Rect.y = window_Surface->h /2;
	box_Rect.w = window_Surface->w;
	box_Rect.h = window_Surface->h /2;

	SDL_Texture* texto1_Texture = load_texture("imagens/texto 1.png", window_Renderer);
	SDL_Texture* texto2_Texture = load_texture("imagens/texto 2.png", window_Renderer);
	SDL_Texture* texto3_Texture = load_texture("imagens/texto 3.png", window_Renderer);
	SDL_Texture* texto4_Texture = load_texture("imagens/texto 4.png", window_Renderer);

	SDL_Rect texto_Rect;
	texto_Rect.x = 0;
	texto_Rect.y = window_Surface->h / 2;
	texto_Rect.w = window_Surface->w;
	texto_Rect.h = window_Surface->h / 2;

	bool prendeu_Assassino = false;
	bool respondeu = false;

	bool chat = false;
	int fala = 1;

	int cenarios_Necessessarios = 4; // <--------------------------------------- CENARIOS NECESSÁRIOS

	// ------------------------------- //

	// booleanas de movimento
	bool esq = false;
	bool dir = false;
	bool cima = false;
	bool baixo = false;

	// contadores de frames
	int frame_Detetive = 0;

	char detetive = 'D';
	int detetive_Linha = 5;
	int detetive_Coluna = 7;

	int detetive_Lado = 3; // WASD = 1234 respectivamente
					      //  1234

	int num_cenario = 1; // 0 = esquerda  | 1 = centro | 2 = direita

	SDL_Event event;
	bool cenario = true;

	SDL_RenderCopy(window_Renderer, background_Texture_Centro, NULL, NULL);
	SDL_RenderCopy(window_Renderer, detetive_Costa_1_Texture, NULL, &detetive_Rect);

	// SDL_Texture* hitbox_Texture = load_texture("imagens/fundo preto.png", window_Renderer); // <---- apenas para debugar

	while (cenario && *vivo)
	{
		// SDL_RenderCopy(window_Renderer, hitbox_Texture, NULL, &detetive_Rect_Hitbox); // <---- apenas para debugar

		SDL_RenderPresent(window_Renderer);

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				cenario = false;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					cenario = false;
					break;

				case SDLK_w:
					if (chat == false || respondeu == true)
					{
						cima = true;
					}

					detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h * 3 / 4;
					break;

				case SDLK_a:
					if (chat == false || respondeu)
					{
						esq = true;
					}

					detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w * 3 / 4;
					break;

				case SDLK_s:
					if (chat == false || respondeu)
					{
						baixo = true;
					}

					detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h / 4;
					break;

				case SDLK_d:
					if (chat == false || respondeu)
					{
						dir = true;
					}

					detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w / 4;
					break;

				case SDLK_k:
					if (detetive_Linha == 4 && detetive_Coluna == 7 && detetive_Lado == 1 && chat == false && fala == 1)
					{
						chat = true;
					}
					else if (detetive_Linha == 4 && detetive_Coluna == 7 && chat == true && !respondeu)
					{
						fala += 1;
					}
					break;

				case SDLK_x:
					printf("cenarios completos = %i \n", *cenarios_Completos);
					save_game(*cenarios_Completos, dificuldade, som_Ligado);
					break;

				case SDLK_1:
					printf("1");
					if (fala == 1)
					{
						prendeu_Assassino = true;
						fala += 1;
					}
					break;

				case SDLK_2:
					printf("2");
					if (fala == 1)
					{
						prendeu_Assassino = false;
						fala += 1;
					}
					break;

				case SDLK_3:
					printf("3");
					if (fala == 1)
					{
						prendeu_Assassino = false;
						fala += 1;
					}
					break;

				case SDLK_4:
					printf("4");
					if (fala == 1)
					{
						prendeu_Assassino = false;
						fala += 1;
					}
					break;
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_w:
					cima = false;

					detetive_Lado = 1;

					detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h / 2;
					break;

				case SDLK_a:
					esq = false;

					detetive_Lado = 2;

					detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w / 2;
					break;

				case SDLK_s:
					baixo = false;

					detetive_Lado = 3;

					detetive_Rect_Hitbox.y = detetive_Rect.y + detetive_Rect.h / 2;
					break;

				case SDLK_d:
					dir = false;

					detetive_Lado = 4;

					detetive_Rect_Hitbox.x = detetive_Rect.x + detetive_Rect.w / 2;
					break;
				}
			} // Fim do switch das teclas

		} // fim do loop de eventos

		// Coloca o detetive na matriz em função do seu retangulo no grid
		for (int linha = 0; linha < 12; linha++)
		{
			for (int coluna = 0; coluna < 15; coluna++)
			{
				if (SDL_HasIntersection(&detetive_Rect_Hitbox, &grid[linha][coluna]))
				{
					printf("detetive_Linha = %i \n", linha);
					printf("detetive_Coluna = %i \n\n", coluna);

					if (num_cenario == 1 && delegacia_Centro[linha][coluna]	== '_') // Se está na delegacia centro
					{
						delegacia_Centro[linha][coluna] = detetive;
					}
					else if (num_cenario == 0 && delegacia_Esquerda[linha][coluna] == '_') // Se o detetive está na delegacia esquerda
					{
						delegacia_Esquerda[linha][coluna] = detetive;
					}
					else if (num_cenario == 2 && delegacia_Direita[linha][coluna] == '_') // Se o detetive está na delegacia direita
					{
						delegacia_Direita[linha][coluna] = detetive;
					}

					detetive_Linha = linha;
					detetive_Coluna = coluna;
				}
				else
				{
					if (num_cenario == 1 && delegacia_Centro[linha][coluna] == 'D')
					{
						delegacia_Centro[linha][coluna] = '_';
					}
					else if (num_cenario == 0 && delegacia_Esquerda[linha][coluna] == 'D')
					{
						delegacia_Esquerda[linha][coluna] = '_';
					}
					else if (num_cenario == 2 && delegacia_Direita[linha][coluna] == 'D')
					{
						delegacia_Direita[linha][coluna] = '_';
					}
				}
			}
		}

		// Movimentação do detetive na matriz e cenário

		if (cima == true)
		{
			if (num_cenario == 1)
			{
				if (delegacia_Centro[detetive_Linha - 1][detetive_Coluna] == '_')
				{
					detetive_Rect.y -= 8;
					detetive_Rect_Hitbox.y -= 8;
				}
			}
			else if (num_cenario == 0)
			{
				if (delegacia_Esquerda[detetive_Linha - 1][detetive_Coluna] == '_')
				{
					detetive_Rect.y -= 8;
					detetive_Rect_Hitbox.y -= 8;
				}
			}
			else if (num_cenario == 2)
			{
				if (delegacia_Direita[detetive_Linha - 1][detetive_Coluna] == '_')
				{
					detetive_Rect.y -= 8;
					detetive_Rect_Hitbox.y -= 8;
				}
			}
			
		}
		else if (esq == true)
		{
			if (num_cenario == 1)
			{
				if (delegacia_Centro[detetive_Linha][detetive_Coluna - 1] == '_')
				{
					detetive_Rect.x -= 8;
					detetive_Rect_Hitbox.x -= 8;
				}
			}
			else if (num_cenario == 0)
			{
				if (delegacia_Esquerda[detetive_Linha][detetive_Coluna - 1] == '_')
				{
					detetive_Rect.x -= 8;
					detetive_Rect_Hitbox.x -= 8;
				}
			}
			else if (num_cenario == 2)
			{
				if (delegacia_Direita[detetive_Linha][detetive_Coluna - 1] == '_')
				{
					detetive_Rect.x -= 8;
					detetive_Rect_Hitbox.x -= 8;
				}
			}
			
		}
		else if (baixo == true)
		{
			if (num_cenario == 1)
			{
				if (delegacia_Centro[detetive_Linha + 1][detetive_Coluna] == '_')
				{
					detetive_Rect.y += 8;
					detetive_Rect_Hitbox.y += 8;
				}
			}
			else if (num_cenario == 0)
			{
				if (delegacia_Esquerda[detetive_Linha + 1][detetive_Coluna] == '_')
				{
					detetive_Rect.y += 8;
					detetive_Rect_Hitbox.y += 8;
				}
			}
			else if (num_cenario == 2)
			{
				if (delegacia_Direita[detetive_Linha + 1][detetive_Coluna] == '_')
				{
					detetive_Rect.y += 8;
					detetive_Rect_Hitbox.y += 8;
				}
			}
		}
		else if (dir == true)
		{
			if (num_cenario == 1)
			{
				if (delegacia_Centro[detetive_Linha][detetive_Coluna + 1] == '_')
				{
					detetive_Rect.x += 8;
					detetive_Rect_Hitbox.x += 8;
				}
			}
			else if (num_cenario == 0)
			{
				if (delegacia_Esquerda[detetive_Linha][detetive_Coluna + 1] == '_')
				{
					detetive_Rect.x += 8;
					detetive_Rect_Hitbox.x += 8;
				}
			}
			else if (num_cenario == 2)
			{
				if (delegacia_Direita[detetive_Linha][detetive_Coluna + 1] == '_')
				{
					detetive_Rect.x += 8;
					detetive_Rect_Hitbox.x += 8;
				}
			}
		}

		// Checa em que sala o detetive está e, em seguida, as suas coordenadas
		if (num_cenario == 1) // centro da delegacia
		{
			// Se o detetive estivar nessas coordenadas do mapa ele passa pra sala da esquerda delegacia
			if (detetive_Linha == 4 && detetive_Coluna == 0)
			{
				num_cenario = 0;

				detetive_Linha = 4;
				detetive_Coluna = 13;

				detetive_Rect.x = grid[4][13].x -16;
				detetive_Rect.y = grid[4][13].y -16;

				detetive_Rect_Hitbox.x = grid[4][13].x - 16 + detetive_Rect.w / 2;
				detetive_Rect_Hitbox.y = grid[4][13].y - 16 + detetive_Rect.h / 2;
			}
			// Se o detetive estiver nessas coordenadas do mapa ele passa pra sala da direita da delegacia
			else if(detetive_Linha == 4 && detetive_Coluna == 14)
			{
				num_cenario = 2;

				detetive_Linha = 4;
				detetive_Coluna = 1;

				detetive_Rect.x = grid[4][1].x -16;
				detetive_Rect.y = grid[4][1].y -16;

				detetive_Rect_Hitbox.x = grid[4][1].x - 16 + detetive_Rect.w / 2;
				detetive_Rect_Hitbox.y = grid[4][1].y - 16 + detetive_Rect.h / 2;
			}
			else if (detetive_Linha == 11 && detetive_Coluna == 7)
			{
				SDL_RenderSetViewport(window_Renderer, main_Rect);

				Mix_HaltMusic(); // Para a música da delegacia para que nao tenha um ruido quando a musica retornar a tocar

				escolha_cenarios(window_Renderer, window_Surface, main_Rect, dificuldade, som_Ligado, cenarios_Completos, vivo);

				coloca_fundo_preto(window_Renderer);

				SDL_RenderSetViewport(window_Renderer, &cenario_Rect);

				// ---- //

				cima = false; esq = false; baixo = false; dir = false; // Apenas para prevenir um bug

				// ---- //

				detetive_Linha = 10;
				detetive_Coluna = 7;

				detetive_Rect.x = grid[10][7].x - 16;
				detetive_Rect.y = grid[10][7].y - 16;

				detetive_Rect_Hitbox.x = grid[10][7].x - 16 + detetive_Rect.w / 2;
				detetive_Rect_Hitbox.y = grid[10][7].y - 16 + detetive_Rect.h / 2;

				if (som_Ligado)
				{
					// SDL_Delay(50);
					Mix_PlayMusic(musica_jogo, -1);
				}
			}
		}
		else if (num_cenario == 0) // esquerda da delegacia
		{
			// Se o detetive estiver nessas coordenadas do mapa ele passa para a sala do centro da delegacia
			if (detetive_Linha == 4 && detetive_Coluna == 14)
			{
				num_cenario = 1;

				detetive_Linha = 4;
				detetive_Coluna = 1;

				detetive_Rect.x = grid[4][1].x -16;
				detetive_Rect.y = grid[4][1].y -16;

				detetive_Rect_Hitbox.x = grid[4][1].x - 16 + detetive_Rect.w / 2;
				detetive_Rect_Hitbox.y = grid[4][1].y - 16 + detetive_Rect.h / 2;
			}
		}
		else if (num_cenario == 2) // direita da delegacia
		{
			// Se o detetive estivar nessas coordenadas do mapa ele passa pra sala do centro da delegacia
			if (detetive_Linha == 4 && detetive_Coluna == 0)
			{
				num_cenario = 1;

				detetive_Linha = 4;
				detetive_Coluna = 13;

				detetive_Rect.x = grid[4][13].x -16;
				detetive_Rect.y = grid[4][13].y -16;

				detetive_Rect_Hitbox.x = grid[4][13].x - 16 + detetive_Rect.w / 2;
				detetive_Rect_Hitbox.y = grid[4][13].y - 16 + detetive_Rect.h / 2;
			}
		}

		// SDL copy das texturas do cenário

		if (num_cenario == 1)
		{
			SDL_RenderCopy(window_Renderer, background_Texture_Centro, NULL, NULL);
		}
		else if (num_cenario == 0)
		{
			SDL_RenderCopy(window_Renderer, background_Texture_Esquerda, NULL, NULL);
		}
		else if (num_cenario == 2)
		{
			SDL_RenderCopy(window_Renderer, background_Texture_Direita, NULL, NULL);
		}


		// SDL copy das texturas do detetive

		if (cima)
		{
			switch (frame_Detetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive_Costa_1_Texture, NULL, &detetive_Rect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive_Costa_2_Texture, NULL, &detetive_Rect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive_Costa_3_Texture, NULL, &detetive_Rect);
				break;
			}
		}
		else if (esq)
		{
			switch (frame_Detetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Esquerdo_1_Texture, NULL, &detetive_Rect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Esquerdo_2_Texture, NULL, &detetive_Rect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Esquerdo_3_Texture, NULL, &detetive_Rect);
				break;
			}
		}
		else if (baixo)
		{
			switch (frame_Detetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive_Frente_1_Texture, NULL, &detetive_Rect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive_Frente_2_Texture, NULL, &detetive_Rect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive_Frente_3_Texture, NULL, &detetive_Rect);
				break;
			}
		}
		else if (dir)
		{
			switch (frame_Detetive)
			{
			case 0:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Direito_1_Texture, NULL, &detetive_Rect);
				break;
			case 1:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Direito_2_Texture, NULL, &detetive_Rect);
				break;
			case 2:
				SDL_RenderCopy(window_Renderer, detetive_Lado_Direito_3_Texture, NULL, &detetive_Rect);
				break;
			}
		}
		else
		{
			if (detetive_Lado == 1)
			{
				SDL_RenderCopy(window_Renderer, detetive_Costa_1_Texture, NULL, &detetive_Rect);
			}
			else if (detetive_Lado == 2)
			{
				SDL_RenderCopy(window_Renderer, detetive_Lado_Esquerdo_2_Texture, NULL, &detetive_Rect);
			}
			else if (detetive_Lado == 3)
			{
				SDL_RenderCopy(window_Renderer, detetive_Frente_1_Texture, NULL, &detetive_Rect);
			}
			else if (detetive_Lado == 4)
			{
				SDL_RenderCopy(window_Renderer, detetive_Lado_Direito_2_Texture, NULL, &detetive_Rect);
			}
		}

		// ------------- //

		frame_Detetive += 1;

		if (frame_Detetive == 3)
		{
			frame_Detetive = 0;
		}

		// ------------- //

		// SDL copy das teturas que ficam por cima do detetive


		if (num_cenario == 1)
		{
			SDL_RenderCopy(window_Renderer, planta_Texture, NULL, &planta_Direita_Rect);
			SDL_RenderCopy(window_Renderer, planta_Texture, NULL, &planta_Esquerda_Rect);
			SDL_RenderCopy(window_Renderer, lixeira_Texture, NULL, &lixeira_Rect);

			SDL_RenderCopy(window_Renderer, npc_Texture, NULL, &npc_Rect);
		}
		else if (num_cenario == 0)
		{
			SDL_RenderCopy(window_Renderer, bancadas_Texture, NULL, NULL);
		}
		else if (num_cenario == 2 && prendeu_Assassino)
		{
			SDL_RenderCopy(window_Renderer, assassino_Texture, NULL, &assassino_Rect);
		}

		if (chat && !respondeu)
		{
			SDL_RenderSetViewport(window_Renderer, main_Rect);

			SDL_RenderCopy(window_Renderer, box_Texture, NULL, &box_Rect);
			
			if (*cenarios_Completos < cenarios_Necessessarios)
			{
				SDL_RenderCopy(window_Renderer, texto1_Texture, NULL, &texto_Rect);

				if (fala == 2)
				{
					coloca_fundo_preto(window_Renderer);

					chat = false;
					fala = 1;
				}
			}
			else
			{
				if (fala == 1)
				{
					SDL_RenderCopy(window_Renderer, texto2_Texture, NULL, &texto_Rect);
				}
				else if (fala == 2)
				{
					if (prendeu_Assassino)
					{
						SDL_RenderCopy(window_Renderer, texto4_Texture, NULL, &texto_Rect);
						printf("fala = %i", fala);
						if (fala == 3)
						{
							chat = false;
							coloca_fundo_preto(window_Renderer);

							respondeu = true;

							SDL_DestroyTexture(box_Texture);
						}
					}
					else
					{
						SDL_RenderCopy(window_Renderer, texto3_Texture, NULL, &texto_Rect);
						printf("fala = %i", fala);
						if (fala == 3)
						{
							chat = false;
							coloca_fundo_preto(window_Renderer);

							respondeu = true;

							SDL_DestroyTexture(box_Texture);
						}
					}
				}
				else if (fala == 3)
				{
					chat = false;
					coloca_fundo_preto(window_Renderer);

					respondeu = true;
				}


				

			}

			SDL_RenderSetViewport(window_Renderer, &cenario_Rect);
		}

		// ------------- //

		SDL_Delay(50); // Fim da logica da movimentação e renderização

		// ------------- //

		// Mostra o mapa da delegacia
		
		
		for (int linha = 0; linha < 12; linha++)
		{
			for (int coluna = 0; coluna < 15; coluna++)
			{
				if (num_cenario == 1)
				{
					printf("%c ", delegacia_Centro[linha][coluna]);
				}
				else if (num_cenario == 0)
				{
					printf("%c ", delegacia_Esquerda[linha][coluna]);
				}
				else if (num_cenario == 2)
				{
					printf("%c ", delegacia_Direita[linha][coluna]);
				}
			}
			printf("\n");
		}


	} // fim do while(cenario)

	// Finalização da função

	SDL_DestroyTexture(background_Texture_Centro);
	SDL_DestroyTexture(background_Texture_Direita);
	SDL_DestroyTexture(background_Texture_Esquerda);

	SDL_DestroyTexture(detetive_Costa_1_Texture);
	SDL_DestroyTexture(detetive_Costa_2_Texture);
	SDL_DestroyTexture(detetive_Costa_3_Texture);
	SDL_DestroyTexture(detetive_Frente_1_Texture);
	SDL_DestroyTexture(detetive_Frente_2_Texture);
	SDL_DestroyTexture(detetive_Frente_3_Texture);
	SDL_DestroyTexture(detetive_Lado_Direito_1_Texture);
	SDL_DestroyTexture(detetive_Lado_Direito_2_Texture);
	SDL_DestroyTexture(detetive_Lado_Direito_3_Texture);
	SDL_DestroyTexture(detetive_Lado_Esquerdo_1_Texture);
	SDL_DestroyTexture(detetive_Lado_Esquerdo_2_Texture);
	SDL_DestroyTexture(detetive_Lado_Esquerdo_3_Texture);

	SDL_DestroyTexture(planta_Texture);
	SDL_DestroyTexture(lixeira_Texture);
	SDL_DestroyTexture(bancadas_Texture);

	SDL_DestroyTexture(box_Texture);
	SDL_DestroyTexture(assassino_Texture);
	SDL_DestroyTexture(npc_Texture);
	SDL_DestroyTexture(texto1_Texture);
	SDL_DestroyTexture(texto2_Texture);
	SDL_DestroyTexture(texto3_Texture);
	SDL_DestroyTexture(texto4_Texture);

	background_Texture_Centro = NULL;
	background_Texture_Direita = NULL;
	background_Texture_Esquerda = NULL;

	box_Texture = NULL;
	assassino_Texture = NULL;
	npc_Texture = NULL;
	texto1_Texture = NULL;
	texto2_Texture = NULL;
	texto3_Texture = NULL;
	texto4_Texture = NULL;


	detetive_Costa_1_Texture = NULL;
	detetive_Costa_2_Texture = NULL;
	detetive_Costa_3_Texture = NULL;
	detetive_Frente_1_Texture = NULL;
	detetive_Frente_2_Texture = NULL;
	detetive_Frente_3_Texture = NULL;
	detetive_Lado_Direito_1_Texture = NULL;
	detetive_Lado_Direito_2_Texture = NULL;
	detetive_Lado_Direito_3_Texture = NULL;
	detetive_Lado_Esquerdo_1_Texture = NULL;
	detetive_Lado_Esquerdo_2_Texture = NULL;
	detetive_Lado_Esquerdo_3_Texture = NULL;

	planta_Texture = NULL;
	lixeira_Texture = NULL;
	bancadas_Texture = NULL;

	Mix_HaltMusic();

} // Fim da função cenario_delegacia()

// --------------------------------------------------------------------------------------- //

int main(int argc, char* argv[])
{
	init();

	int window_Width = 1280;
	int window_Height = 720;

	bool game_loop = true;

	int dificuldade = 0;
	bool vivo = true;

	bool load_game = false;
	bool som_Ligado = true;

	int cenarios_Completos = 0;

	// ------------------------------- //
	//  =-=   Núcleo do código   =-=   //
	SDL_Window* main_Window = SDL_CreateWindow("Jogo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_Width, window_Height, SDL_WINDOW_SHOWN);
	SDL_Surface* main_Surface = SDL_GetWindowSurface(main_Window);

	SDL_Renderer* window_Renderer = SDL_CreateRenderer(main_Window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(window_Renderer, 0xFF, 0xFF, 0xFF, 255);

	SDL_Rect main_Rect;
	main_Rect.x = 0;
	main_Rect.y = 0;
	main_Rect.w = window_Width;
	main_Rect.h = window_Height;
	
	// ------------------------------- //

	menu(window_Renderer, main_Surface, &load_game, &som_Ligado);

	if (load_game)
	{
		carregar_jogo(&cenarios_Completos, &dificuldade, &som_Ligado);
	}
	else
	{
		save_game(cenarios_Completos, dificuldade, som_Ligado);

		escolher_dificuldade(window_Renderer, main_Surface, &dificuldade);
		
		inicio_jornal(window_Renderer, main_Surface);
	}
	
	cenario_delegacia(window_Renderer, main_Surface, &main_Rect, load_game, dificuldade, som_Ligado, &cenarios_Completos, &vivo);
	

	// ------------------------------- //

	quit();

	return 0;
}
