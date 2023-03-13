
int NETSCAPE_SPKI_print(BIO *out,NETSCAPE_SPKI *spki)

{
  byte bVar1;
  ASN1_IA5STRING *pAVar2;
  uchar *puVar3;
  int iVar4;
  EVP_PKEY *pkey;
  int iVar5;
  char *pcVar6;
  
  BIO_printf(out,"Netscape SPKI:\n");
  iVar4 = OBJ_obj2nid(spki->spkac->pubkey->algor->algorithm);
  pcVar6 = "UNKNOWN";
  if (iVar4 != 0) {
    pcVar6 = OBJ_nid2ln(iVar4);
  }
  BIO_printf(out,"  Public Key Algorithm: %s\n",pcVar6);
  pkey = X509_PUBKEY_get(spki->spkac->pubkey);
  if (pkey == (EVP_PKEY *)0x0) {
    BIO_printf(out,"  Unable to load public key\n",pcVar6);
  }
  else {
    EVP_PKEY_print_public(out,pkey,4,(ASN1_PCTX *)0x0);
    EVP_PKEY_free(pkey);
  }
  pAVar2 = spki->spkac->challenge;
  if (pAVar2->length != 0) {
    BIO_printf(out,"  Challenge String: %s\n",pAVar2->data);
  }
  iVar4 = OBJ_obj2nid(spki->sig_algor->algorithm);
  pcVar6 = "UNKNOWN";
  if (iVar4 != 0) {
    pcVar6 = OBJ_nid2ln(iVar4);
  }
  BIO_printf(out,"  Signature Algorithm: %s",pcVar6);
  iVar4 = spki->signature->length;
  puVar3 = spki->signature->data;
  if (0 < iVar4) {
    iVar5 = 0;
    do {
      if (iVar5 == (iVar5 / 0x12) * 0x12) {
        BIO_write(out,&DAT_082280ff,7);
        if (iVar4 == iVar5 + 1) goto LAB_08144799;
        bVar1 = puVar3[iVar5];
      }
      else {
        if (iVar4 == iVar5 + 1) goto LAB_08144799;
        bVar1 = puVar3[iVar5];
      }
      iVar5 = iVar5 + 1;
      BIO_printf(out,"%02x%s",(uint)bVar1,":");
    } while( true );
  }
LAB_081447b1:
  BIO_write(out,&DAT_081f15cb,1);
  return 1;
LAB_08144799:
  BIO_printf(out,"%02x%s",(uint)puVar3[iVar5],&DAT_081eca46);
  goto LAB_081447b1;
}

