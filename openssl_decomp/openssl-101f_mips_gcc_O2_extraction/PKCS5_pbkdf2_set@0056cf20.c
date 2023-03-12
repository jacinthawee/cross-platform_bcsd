
X509_ALGOR * PKCS5_pbkdf2_set(int iter,uchar *salt,int saltlen,int prf_nid,int keylen)

{
  undefined *puVar1;
  undefined4 *val;
  ASN1_STRING *pAVar2;
  undefined4 *puVar3;
  uchar *puVar4;
  int iVar5;
  X509_ALGOR *pXVar6;
  ASN1_OBJECT *pAVar7;
  ASN1_TYPE *pAVar8;
  long v;
  
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)PBKDF2PARAM_it);
  if ((val != (undefined4 *)0x0) &&
     (pAVar2 = ASN1_STRING_type_new(4), puVar1 = PTR_CRYPTO_malloc_006a8108,
     pAVar2 != (ASN1_STRING *)0x0)) {
    puVar3 = (undefined4 *)*val;
    if (saltlen == 0) {
      saltlen = 8;
    }
    puVar3[1] = pAVar2;
    *puVar3 = 4;
    puVar4 = (uchar *)(*(code *)puVar1)(saltlen,"p5_pbev2.c",0xd9);
    pAVar2->data = puVar4;
    if (puVar4 != (uchar *)0x0) {
      pAVar2->length = saltlen;
      if (salt == (uchar *)0x0) {
        iVar5 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(puVar4,saltlen);
        if (iVar5 < 0) {
          pXVar6 = (X509_ALGOR *)0x0;
          goto LAB_0056d158;
        }
      }
      else {
        (*(code *)PTR_memcpy_006aabf4)(puVar4,salt,saltlen);
      }
      v = 0x800;
      if (0 < iter) {
        v = iter;
      }
      iVar5 = ASN1_INTEGER_set((ASN1_INTEGER *)val[1],v);
      if (iVar5 != 0) {
        if (0 < keylen) {
          pAVar2 = ASN1_STRING_type_new(2);
          val[2] = pAVar2;
          if ((pAVar2 == (ASN1_STRING *)0x0) ||
             (iVar5 = ASN1_INTEGER_set(pAVar2,keylen), iVar5 == 0)) goto LAB_0056d154;
        }
        if ((0 < prf_nid) && (prf_nid != 0xa3)) {
          pXVar6 = X509_ALGOR_new();
          val[3] = pXVar6;
          if (pXVar6 == (X509_ALGOR *)0x0) goto LAB_0056d154;
          pAVar7 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(prf_nid);
          X509_ALGOR_set0(pXVar6,pAVar7,5,(void *)0x0);
        }
        pXVar6 = X509_ALGOR_new();
        if (pXVar6 != (X509_ALGOR *)0x0) {
          pAVar7 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(0x45);
          pXVar6->algorithm = pAVar7;
          pAVar8 = ASN1_TYPE_new();
          pXVar6->parameter = pAVar8;
          if ((pAVar8 != (ASN1_TYPE *)0x0) &&
             (iVar5 = (*(code *)PTR_ASN1_item_pack_006a9f14)(val,PBKDF2PARAM_it,&pAVar8->value),
             iVar5 != 0)) {
            pXVar6->parameter->type = 0x10;
            ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBKDF2PARAM_it);
            return pXVar6;
          }
          goto LAB_0056d158;
        }
      }
    }
  }
LAB_0056d154:
  pXVar6 = (X509_ALGOR *)0x0;
LAB_0056d158:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xdb,0x41,"p5_pbev2.c",0x113);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBKDF2PARAM_it);
  X509_ALGOR_free(pXVar6);
  return (X509_ALGOR *)0x0;
}

