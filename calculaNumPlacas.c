
int calculaNumPlacasSol(float consumoMedioAnual)
{
    int potenciaDasPlacas = 340;
    int numeroPlacas;
    numeroPlacas = ceil((consumoMedioAnual*1000) / (potenciaDasPlacas * 5 * 0.8 * 30));

    return numeroPlacas;
}
