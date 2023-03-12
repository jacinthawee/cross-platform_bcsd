
char * i2s_ASN1_ENUMERATED_TABLE(X509V3_EXT_METHOD *meth,ASN1_ENUMERATED *aint)

{
  int *piVar1;
  long lVar2;
  char *pcVar3;
  
  lVar2 = ASN1_ENUMERATED_get(aint);
  pcVar3 = *(char **)((int)meth->usr_data + 4);
  piVar1 = (int *)meth->usr_data;
  while( true ) {
    if (pcVar3 == (char *)0x0) {
      pcVar3 = i2s_ASN1_ENUMERATED(meth,aint);
      return pcVar3;
    }
    if (lVar2 == *piVar1) break;
    pcVar3 = (char *)piVar1[4];
    piVar1 = piVar1 + 3;
  }
  pcVar3 = BUF_strdup(pcVar3);
  return pcVar3;
}

