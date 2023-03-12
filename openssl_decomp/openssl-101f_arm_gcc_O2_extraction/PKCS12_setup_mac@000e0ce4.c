
int PKCS12_setup_mac(PKCS12 *p12,int iter,uchar *salt,int saltlen,EVP_MD *md_type)

{
  PKCS12_MAC_DATA *pPVar1;
  ASN1_STRING *pAVar2;
  ASN1_TYPE *pAVar3;
  ASN1_OBJECT *pAVar4;
  int iVar5;
  X509_ALGOR *pXVar6;
  X509_ALGOR *pXVar7;
  ASN1_OCTET_STRING *pAVar8;
  
  pPVar1 = PKCS12_MAC_DATA_new();
  p12->mac = pPVar1;
  if (pPVar1 == (PKCS12_MAC_DATA *)0x0) {
    return 0;
  }
  if (1 < iter) {
    pAVar2 = ASN1_STRING_type_new(2);
    pPVar1->iter = pAVar2;
    if (pAVar2 == (ASN1_STRING *)0x0) {
      ERR_put_error(0x23,0x7a,0x41,"p12_mutl.c",0xa2);
      return 0;
    }
    pAVar3 = (ASN1_TYPE *)ASN1_INTEGER_set(p12->mac->iter,iter);
    if (pAVar3 == (ASN1_TYPE *)0x0) {
      iVar5 = 0xa6;
      goto LAB_000e0da0;
    }
    pPVar1 = p12->mac;
  }
  pAVar8 = pPVar1->salt;
  if (saltlen == 0) {
    saltlen = 8;
  }
  pAVar8->length = saltlen;
  pAVar3 = (ASN1_TYPE *)CRYPTO_malloc(saltlen,"p12_mutl.c",0xac);
  iVar5 = 0xad;
  pAVar8->data = (uchar *)pAVar3;
  if (pAVar3 != (ASN1_TYPE *)0x0) {
    if (salt == (uchar *)0x0) {
      iVar5 = RAND_pseudo_bytes(p12->mac->salt->data,saltlen);
      if (iVar5 < 0) {
        return 0;
      }
    }
    else {
      memcpy(p12->mac->salt->data,salt,saltlen);
    }
    pXVar7 = p12->mac->dinfo->algor;
    iVar5 = EVP_MD_type(md_type);
    pAVar4 = OBJ_nid2obj(iVar5);
    pXVar6 = p12->mac->dinfo->algor;
    pXVar7->algorithm = pAVar4;
    pAVar3 = ASN1_TYPE_new();
    pXVar6->parameter = pAVar3;
    if (pAVar3 != (ASN1_TYPE *)0x0) {
      p12->mac->dinfo->algor->parameter->type = 5;
      return 1;
    }
    iVar5 = 0xb7;
  }
LAB_000e0da0:
  ERR_put_error(0x23,0x7a,0x41,"p12_mutl.c",iVar5);
  return (int)pAVar3;
}

