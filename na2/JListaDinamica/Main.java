import java.util.Scanner;

class Item
{
    int chave;
    Item proximo;
}

class Lista
{
    Item primeiro;
}

public class Main
{
    public static void main(String[] args)
    {
        Lista lista = criaLista();
        Item it;
        Scanner scan = new Scanner(System.in);
        int chave;
        char op;

        while(scan.hasNext())
        {
            op = scan.next().charAt(0);
            if(op == 'I')
            {
                chave = scan.nextInt();
                inserir(lista, criaItem(chave));
            }
            else if(op == 'R')
            {
                chave = scan.nextInt();
                it = remover(lista, chave);
                if(it != null)
                {
                    System.out.println("item " + it.chave + " removido da lista");
                }
            }
            else if(op == 'B')
            {
                chave = scan.nextInt();
                System.out.println("item " + chave + (buscar(lista, chave)?" ":" nao ") + "localizado na lista");
            }
            else // M
            {
                mostrar(lista);
            }
        }

    }

    public static Lista criaLista()
    {
        Lista l = new Lista();
        if(l != null)
        {
            l.primeiro = null;
        }
        return l;
    }

    public static Item criaItem(int chave)
    {
        Item it = new Item();
        if(it != null)
        {
            it.chave = chave;
            it.proximo = null;
        }
        return it;
    }

    public static void inserir(Lista l, Item novo)
    {
        Item anterior = null, atual = l.primeiro;

        while(atual != null && atual.chave < novo.chave)
        {
            anterior = atual;
            atual = atual.proximo;
        }

        if(atual != null) // inicio nao vazio ou meio
        {
            if(anterior != null) // meio
            {
                anterior.proximo = novo;
            }
            else // inicio
            {
                l.primeiro = novo;
            }
            novo.proximo = atual;
        }
        else // final ou inicio de uma lista vazia
        {
            if(anterior != null) // final
            {
                novo.proximo = anterior.proximo;
                anterior.proximo = novo;
            }
            else // inicio
            {
                l.primeiro = novo;
            }
        }
    }

    public static Item remover(Lista l, int chave)
    {
        Item anterior = null, atual = l.primeiro;

        while(atual != null && atual.chave < chave)
        {
            anterior = atual;
            atual = atual.proximo;
        }

        if(atual != null) // encontrei uma chave > ou =
        {
            if(atual.chave == chave)
            {
                if(anterior != null) // meio ou final
                {
                    anterior.proximo = atual.proximo;
                }
                else // primeiro
                {
                    l.primeiro = atual.proximo;
                }
            }
            else
            {
                atual = null;
            }
        }
        return atual;
    }

    public static boolean buscar(Lista l, int chave)
    {
        Item it = l.primeiro;

        while(it != null && it.chave < chave)
        {
            it = it.proximo;
        }

        return it != null && it.chave == chave;
    }

    public static void mostrar(Lista l)
    {
        Item it = l.primeiro;

        while(it != null)
        {
            System.out.print(it.chave + (it.proximo != null?" ":"\n"));
            it = it.proximo;
        }
    }
}