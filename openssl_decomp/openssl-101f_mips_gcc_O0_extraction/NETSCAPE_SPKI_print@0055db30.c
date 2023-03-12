
int NETSCAPE_SPKI_print(BIO *out,NETSCAPE_SPKI *spki)

{
  int iVar1;
  EVP_PKEY *pkey;
  ASN1_IA5STRING *pAVar2;
  char *pcVar3;
  uchar uVar4;
  int iVar5;
  uchar *puVar6;
  
  (*(code *)PTR_BIO_printf_006a7f38)(out,"Netscape SPKI:\n");
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(spki->spkac->pubkey->algor->algorithm);
  if (iVar1 == 0) {
    pcVar3 = "UNKNOWN";
  }
  else {
    pcVar3 = (char *)(*(code *)PTR_OBJ_nid2ln_006a821c)(iVar1);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(out,"  Public Key Algorithm: %s\n",pcVar3);
  pkey = X509_PUBKEY_get(spki->spkac->pubkey);
  if (pkey == (EVP_PKEY *)0x0) {
    (*(code *)PTR_BIO_printf_006a7f38)(out,"  Unable to load public key\n");
  }
  else {
    EVP_PKEY_print_public(out,pkey,4,(ASN1_PCTX *)0x0);
    EVP_PKEY_free(pkey);
  }
  pAVar2 = spki->spkac->challenge;
  if (pAVar2->length != 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(out,"  Challenge String: %s\n",pAVar2->data);
  }
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(spki->sig_algor->algorithm);
  if (iVar1 == 0) {
    pcVar3 = "UNKNOWN";
  }
  else {
    pcVar3 = (char *)(*(code *)PTR_OBJ_nid2ln_006a821c)(iVar1);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(out,"  Signature Algorithm: %s",pcVar3);
  iVar1 = spki->signature->length;
  puVar6 = spki->signature->data;
  if (0 < iVar1) {
    iVar5 = 0;
    while( true ) {
      if (iVar5 != (iVar5 / 0x12) * 0x12) {
        do {
          iVar5 = iVar5 + 1;
          uVar4 = *puVar6;
          puVar6 = puVar6 + 1;
          if (iVar1 == iVar5) goto LAB_0055dd48;
          (*(code *)PTR_BIO_printf_006a7f38)(out,"%02x%s",uVar4,":");
        } while (iVar5 != (iVar5 / 0x12) * 0x12);
      }
      iVar5 = iVar5 + 1;
      (*(code *)PTR_BIO_write_006a7f14)(out,&DAT_0066a8f0,7);
      uVar4 = *puVar6;
      if (iVar1 == iVar5) break;
      puVar6 = puVar6 + 1;
      (*(code *)PTR_BIO_printf_006a7f38)(out,"%02x%s",uVar4,":");
    }
LAB_0055dd48:
    (*(code *)PTR_BIO_printf_006a7f38)(out,"%02x%s",uVar4,"");
  }
  (*(code *)PTR_BIO_write_006a7f14)(out,"\n",1);
  return 1;
}

