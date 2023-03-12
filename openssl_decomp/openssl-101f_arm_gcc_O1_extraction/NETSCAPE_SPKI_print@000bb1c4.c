
int NETSCAPE_SPKI_print(BIO *out,NETSCAPE_SPKI *spki)

{
  int iVar1;
  EVP_PKEY *pkey;
  char *pcVar2;
  ASN1_IA5STRING *pAVar3;
  int iVar4;
  uint uVar5;
  uchar *puVar6;
  
  BIO_printf(out,"Netscape SPKI:\n");
  iVar1 = OBJ_obj2nid(spki->spkac->pubkey->algor->algorithm);
  pcVar2 = "UNKNOWN";
  if (iVar1 != 0) {
    pcVar2 = OBJ_nid2ln(iVar1);
  }
  BIO_printf(out,"  Public Key Algorithm: %s\n",pcVar2);
  pkey = X509_PUBKEY_get(spki->spkac->pubkey);
  if (pkey == (EVP_PKEY *)0x0) {
    BIO_printf(out,"  Unable to load public key\n");
  }
  else {
    EVP_PKEY_print_public(out,pkey,4,(ASN1_PCTX *)0x0);
    EVP_PKEY_free(pkey);
  }
  pAVar3 = spki->spkac->challenge;
  if (pAVar3->length != 0) {
    BIO_printf(out,"  Challenge String: %s\n",pAVar3->data);
  }
  iVar1 = OBJ_obj2nid(spki->sig_algor->algorithm);
  pcVar2 = "UNKNOWN";
  if (iVar1 != 0) {
    pcVar2 = OBJ_nid2ln(iVar1);
  }
  BIO_printf(out,"  Signature Algorithm: %s",pcVar2);
  iVar1 = spki->signature->length;
  puVar6 = spki->signature->data;
  if (0 < iVar1) {
    iVar4 = 0;
    while( true ) {
      if (iVar4 == (iVar4 / 0x12) * 0x12) {
        BIO_write(out,&DAT_00163240,7);
      }
      uVar5 = (uint)puVar6[iVar4];
      iVar4 = iVar4 + 1;
      if (iVar4 == iVar1) break;
      BIO_printf(out,"%02x%s",uVar5,":");
    }
    BIO_printf(out,"%02x%s",uVar5,"");
  }
  BIO_write(out,"\n",1);
  return 1;
}

