

int findUser(Usuario usuarios[100], int quantidadeUsuarios, int id)
{
    for (int i = 0; i < quantidadeUsuarios; i++)
    {
        if (usuarios[i].id == id)
        {
            return i;
        }
    }
    return -1;
}
