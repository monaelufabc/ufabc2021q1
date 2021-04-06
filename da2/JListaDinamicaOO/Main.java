import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Lista lista = new Lista();
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
                lista.inserir(new Item(chave));
            }
            else if(op == 'R')
            {
                chave = scan.nextInt();
                it = lista.remover(chave);
                if(it != null)
                {
                    System.out.println("item " + it.getChave() + " removido da lista");
                }
            }
            else if(op == 'B')
            {
                chave = scan.nextInt();
                System.out.println("item " + chave + (lista.buscar(chave)?" ":" nao ") + "localizado na lista");
            }
            else // M
            {
                lista.mostrar();
            }
        }
    }
}

class Item
{
    private int chave;
    private Item proximo;

    public Item(int chave)
    {
        this.setChave(chave);
        this.setProximo(null);
    }

    public int getChave()
    {
        return this.chave;
    }

    public void setChave(int chave)
    {
        this.chave = chave;
    }

    public Item getProximo()
    {
        return this.proximo;
    }

    public void setProximo(Item proximo)
    {
        this.proximo = proximo;
    }
}

class Lista
{
    private Item primeiro;

    public Lista()
    {
        this.setPrimeiro(null);
    }

    public void setPrimeiro(Item primeiro)
    {
        this.primeiro = primeiro;
    }

    public Item getPrimeiro()
    {
        return this.primeiro;
    }

    public void inserir(Item novo)
    {
        Item anterior = null, atual = this.getPrimeiro();

        while(atual != null && atual.getChave() < novo.getChave())
        {
            anterior = atual;
            atual = atual.getProximo();
        }

        if(atual != null) // inicio nao vazio ou meio
        {
            if(anterior != null) // meio
            {
                anterior.setProximo(novo);
            }
            else // inicio
            {
                this.setPrimeiro(novo);
            }
            novo.setProximo(atual);
        }
        else // inicio vazio ou final
        {
            if(anterior != null) // final
            {
                novo.setProximo(anterior.getProximo());
                anterior.setProximo(novo);
            }
            else // inicio
            {
                this.setPrimeiro(novo);
            }
        }
    }

    public Item remover(int chave)
    {
        Item anterior = null, atual = this.getPrimeiro();

        while(atual != null && atual.getChave() < chave)
        {
            anterior = atual;
            atual = atual.getProximo();
        }

        if(atual != null)
        {
            if(atual.getChave() == chave)
            {
                if(anterior != null) // meio ou final
                {
                    anterior.setProximo(atual.getProximo());
                }
                else // inicio
                {
                    this.setPrimeiro(atual.getProximo());
                }
            }
            else
            {
                atual = null;
            }
        }
        return atual;
    }

    public boolean buscar(int chave)
    {
        Item it = this.getPrimeiro();

        while(it != null && it.getChave() < chave)
        {
            it = it.getProximo();
        }

        return it != null && it.getChave() == chave;
    }

    public void mostrar()
    {
        Item it = this.getPrimeiro();

        while(it != null)
        {
            System.out.print(it.getChave() + (it.getProximo() != null ? " " : "\n"));
            it = it.getProximo();
        }
    }
}