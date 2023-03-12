
X509_ALGOR * PKCS5_pbkdf2_set(int iter,uchar *salt,int saltlen,int prf_nid,int keylen)

{
  undefined *it;
  undefined4 *val;
  ASN1_STRING *pAVar1;
  uchar *buf;
  int iVar2;
  X509_ALGOR *pXVar3;
  ASN1_OBJECT *pAVar4;
  ASN1_TYPE *pAVar5;
  undefined4 *puVar6;
  bool bVar7;
  bool bVar8;
  
  val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)PTR_PBKDF2PARAM_it_000c08f0);
  if ((val != (undefined4 *)0x0) && (pAVar1 = ASN1_STRING_type_new(4), pAVar1 != (ASN1_STRING *)0x0)
     ) {
    puVar6 = (undefined4 *)*val;
    if (saltlen == 0) {
      saltlen = 8;
    }
    puVar6[1] = pAVar1;
    *puVar6 = 4;
    buf = (uchar *)CRYPTO_malloc(saltlen,"p5_pbev2.c",0xdd);
    pAVar1->data = buf;
    if (buf != (uchar *)0x0) {
      pAVar1->length = saltlen;
      if (salt == (uchar *)0x0) {
        iVar2 = RAND_bytes(buf,saltlen);
        if (iVar2 < 1) goto LAB_000c08c0;
      }
      else {
        memcpy(buf,salt,saltlen);
      }
      if (iter < 1) {
        iter = 0x800;
      }
      iVar2 = ASN1_INTEGER_set((ASN1_INTEGER *)val[1],iter);
      if (iVar2 != 0) {
        if (0 < keylen) {
          pAVar1 = ASN1_STRING_type_new(2);
          val[2] = pAVar1;
          if ((pAVar1 == (ASN1_STRING *)0x0) ||
             (iVar2 = ASN1_INTEGER_set(pAVar1,keylen), iVar2 == 0)) goto LAB_000c08c0;
        }
        bVar7 = prf_nid + -0xa3 < 0;
        bVar8 = prf_nid == 0xa3;
        if (!bVar8) {
          bVar7 = prf_nid < 0;
        }
        if ((!bVar8 && prf_nid != 0) && bVar7 == (bVar8 && SBORROW4(prf_nid,0xa3))) {
          pXVar3 = X509_ALGOR_new();
          val[3] = pXVar3;
          if (pXVar3 == (X509_ALGOR *)0x0) goto LAB_000c08c0;
          pAVar4 = OBJ_nid2obj(prf_nid);
          X509_ALGOR_set0(pXVar3,pAVar4,5,(void *)0x0);
        }
        pXVar3 = X509_ALGOR_new();
        if (pXVar3 != (X509_ALGOR *)0x0) {
          pAVar4 = OBJ_nid2obj(0x45);
          pXVar3->algorithm = pAVar4;
          pAVar5 = ASN1_TYPE_new();
          pXVar3->parameter = pAVar5;
          if ((pAVar5 != (ASN1_TYPE *)0x0) &&
             (pAVar1 = ASN1_item_pack(val,(ASN1_ITEM *)PTR_PBKDF2PARAM_it_000c08f0,
                                      &(pAVar5->value).octet_string),
             it = PTR_PBKDF2PARAM_it_000c08f0, pAVar1 != (ASN1_STRING *)0x0)) {
            pXVar3->parameter->type = 0x10;
            ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)it);
            return pXVar3;
          }
          goto LAB_000c08c2;
        }
      }
    }
  }
LAB_000c08c0:
  pXVar3 = (X509_ALGOR *)0x0;
LAB_000c08c2:
  ERR_put_error(0xd,0xdb,0x41,"p5_pbev2.c",0x114);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_PBKDF2PARAM_it_000c08f0);
  X509_ALGOR_free(pXVar3);
  return (X509_ALGOR *)0x0;
}

