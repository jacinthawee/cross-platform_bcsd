
int PKCS12_setup_mac(PKCS12 *p12,int iter,uchar *salt,int saltlen,EVP_MD *md_type)

{
  ASN1_OCTET_STRING *pAVar1;
  X509_ALGOR *pXVar2;
  PKCS12_MAC_DATA *pPVar3;
  ASN1_STRING *pAVar4;
  int iVar5;
  uchar *puVar6;
  ASN1_OBJECT *pAVar7;
  ASN1_TYPE *pAVar8;
  
  pPVar3 = PKCS12_MAC_DATA_new();
  p12->mac = pPVar3;
  if (pPVar3 == (PKCS12_MAC_DATA *)0x0) {
    return 0;
  }
  if (1 < iter) {
    pAVar4 = ASN1_STRING_type_new(2);
    pPVar3->iter = pAVar4;
    if (pAVar4 == (ASN1_STRING *)0x0) {
      iVar5 = 0xa2;
      goto LAB_08184ce8;
    }
    iVar5 = ASN1_INTEGER_set(p12->mac->iter,iter);
    if (iVar5 == 0) {
      ERR_put_error(0x23,0x7a,0x41,"p12_mutl.c",0xa6);
      return 0;
    }
    pPVar3 = p12->mac;
  }
  pAVar1 = pPVar3->salt;
  if (saltlen == 0) {
    saltlen = 8;
  }
  pAVar1->length = saltlen;
  puVar6 = (uchar *)CRYPTO_malloc(saltlen,"p12_mutl.c",0xac);
  pAVar1->data = puVar6;
  if (puVar6 == (uchar *)0x0) {
    iVar5 = 0xad;
  }
  else {
    if (salt == (uchar *)0x0) {
      iVar5 = RAND_pseudo_bytes(p12->mac->salt->data,saltlen);
      if (iVar5 < 0) {
        return 0;
      }
    }
    else {
      memcpy(p12->mac->salt->data,salt,saltlen);
    }
    pXVar2 = p12->mac->dinfo->algor;
    iVar5 = EVP_MD_type(md_type);
    pAVar7 = OBJ_nid2obj(iVar5);
    pXVar2->algorithm = pAVar7;
    pXVar2 = p12->mac->dinfo->algor;
    pAVar8 = ASN1_TYPE_new();
    pXVar2->parameter = pAVar8;
    if (pAVar8 != (ASN1_TYPE *)0x0) {
      p12->mac->dinfo->algor->parameter->type = 5;
      return 1;
    }
    iVar5 = 0xb7;
  }
LAB_08184ce8:
  ERR_put_error(0x23,0x7a,0x41,"p12_mutl.c",iVar5);
  return 0;
}

