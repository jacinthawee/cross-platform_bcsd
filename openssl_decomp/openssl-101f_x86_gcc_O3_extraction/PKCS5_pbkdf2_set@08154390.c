
X509_ALGOR * PKCS5_pbkdf2_set(int iter,uchar *salt,int saltlen,int prf_nid,int keylen)

{
  undefined4 *puVar1;
  undefined4 *val;
  ASN1_STRING *pAVar2;
  uchar *buf;
  int iVar3;
  X509_ALGOR *pXVar4;
  ASN1_OBJECT *pAVar5;
  ASN1_TYPE *pAVar6;
  
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)PBKDF2PARAM_it);
  if ((val != (undefined4 *)0x0) && (pAVar2 = ASN1_STRING_type_new(4), pAVar2 != (ASN1_STRING *)0x0)
     ) {
    puVar1 = (undefined4 *)*val;
    puVar1[1] = pAVar2;
    *puVar1 = 4;
    if (saltlen == 0) {
      saltlen = 8;
    }
    buf = (uchar *)CRYPTO_malloc(saltlen,"p5_pbev2.c",0xd9);
    pAVar2->data = buf;
    if (buf != (uchar *)0x0) {
      pAVar2->length = saltlen;
      if (salt == (uchar *)0x0) {
        iVar3 = RAND_pseudo_bytes(buf,saltlen);
        if (iVar3 < 0) goto LAB_08154538;
      }
      else {
        memcpy(buf,salt,saltlen);
      }
      if (iter < 1) {
        iter = 0x800;
      }
      iVar3 = ASN1_INTEGER_set((ASN1_INTEGER *)val[1],iter);
      if (iVar3 != 0) {
        if (0 < keylen) {
          pAVar2 = ASN1_STRING_type_new(2);
          val[2] = pAVar2;
          if ((pAVar2 == (ASN1_STRING *)0x0) ||
             (iVar3 = ASN1_INTEGER_set(pAVar2,keylen), iVar3 == 0)) goto LAB_08154538;
        }
        if ((0 < prf_nid) && (prf_nid != 0xa3)) {
          pXVar4 = X509_ALGOR_new();
          val[3] = pXVar4;
          if (pXVar4 == (X509_ALGOR *)0x0) goto LAB_08154538;
          pAVar5 = OBJ_nid2obj(prf_nid);
          X509_ALGOR_set0((X509_ALGOR *)val[3],pAVar5,5,(void *)0x0);
        }
        pXVar4 = X509_ALGOR_new();
        if (pXVar4 != (X509_ALGOR *)0x0) {
          pAVar5 = OBJ_nid2obj(0x45);
          pXVar4->algorithm = pAVar5;
          pAVar6 = ASN1_TYPE_new();
          pXVar4->parameter = pAVar6;
          if ((pAVar6 != (ASN1_TYPE *)0x0) &&
             (pAVar2 = ASN1_item_pack(val,(ASN1_ITEM *)PBKDF2PARAM_it,&(pAVar6->value).octet_string)
             , pAVar2 != (ASN1_STRING *)0x0)) {
            pXVar4->parameter->type = 0x10;
            ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBKDF2PARAM_it);
            return pXVar4;
          }
          goto LAB_0815453a;
        }
      }
    }
  }
LAB_08154538:
  pXVar4 = (X509_ALGOR *)0x0;
LAB_0815453a:
  ERR_put_error(0xd,0xdb,0x41,"p5_pbev2.c",0x113);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBKDF2PARAM_it);
  X509_ALGOR_free(pXVar4);
  return (X509_ALGOR *)0x0;
}

