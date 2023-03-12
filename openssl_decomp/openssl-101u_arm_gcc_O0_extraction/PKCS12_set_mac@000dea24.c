
int PKCS12_set_mac(PKCS12 *p12,char *pass,int passlen,uchar *salt,int saltlen,int iter,
                  EVP_MD *md_type)

{
  PKCS12_MAC_DATA *pPVar1;
  ASN1_STRING *pAVar2;
  uchar *puVar3;
  ASN1_OBJECT *pAVar4;
  ASN1_TYPE *pAVar5;
  int iVar6;
  X509_ALGOR *pXVar7;
  X509_ALGOR *pXVar8;
  ASN1_OCTET_STRING *pAVar9;
  int local_70;
  undefined auStack_6c [64];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (md_type == (EVP_MD *)0x0) {
    md_type = EVP_sha1();
  }
  pPVar1 = PKCS12_MAC_DATA_new();
  p12->mac = pPVar1;
  if (pPVar1 != (PKCS12_MAC_DATA *)0x0) {
    if (iter < 2) {
LAB_000dea84:
      if (saltlen == 0) {
        saltlen = 8;
      }
      pAVar9 = pPVar1->salt;
      puVar3 = (uchar *)CRYPTO_malloc(saltlen,"p12_mutl.c",0xb0);
      iVar6 = 0xb1;
      pAVar9->data = puVar3;
      if (puVar3 != (uchar *)0x0) {
        pAVar9 = p12->mac->salt;
        pAVar9->length = saltlen;
        puVar3 = pAVar9->data;
        if (salt == (uchar *)0x0) {
          iVar6 = RAND_bytes(puVar3,saltlen);
          if (iVar6 < 1) goto LAB_000deb78;
        }
        else {
          memcpy(puVar3,salt,saltlen);
        }
        pXVar8 = p12->mac->dinfo->algor;
        iVar6 = EVP_MD_type(md_type);
        pAVar4 = OBJ_nid2obj(iVar6);
        pXVar7 = p12->mac->dinfo->algor;
        pXVar8->algorithm = pAVar4;
        pAVar5 = ASN1_TYPE_new();
        pXVar7->parameter = pAVar5;
        if (pAVar5 != (ASN1_TYPE *)0x0) {
          pAVar4 = p12->authsafes->type;
          p12->mac->dinfo->algor->parameter->type = 5;
          iVar6 = OBJ_obj2nid(pAVar4);
          if (iVar6 == 0x15) {
            iVar6 = PKCS12_gen_mac_part_0(p12,pass,passlen,auStack_6c,&local_70);
            if (iVar6 != 0) {
              iVar6 = ASN1_STRING_set(p12->mac->dinfo->digest,auStack_6c,local_70);
              if (iVar6 == 0) {
                ERR_put_error(0x23,0x7b,0x6f,"p12_mutl.c",0x98);
              }
              else {
                iVar6 = 1;
              }
              goto LAB_000deb22;
            }
          }
          else {
            ERR_put_error(0x23,0x6b,0x79,"p12_mutl.c",0x4f);
          }
          iVar6 = 0;
          ERR_put_error(0x23,0x7b,0x6d,"p12_mutl.c",0x94);
          goto LAB_000deb22;
        }
        iVar6 = 0xbc;
      }
    }
    else {
      pAVar2 = ASN1_STRING_type_new(2);
      iVar6 = 0xa6;
      pPVar1->iter = pAVar2;
      if (pAVar2 != (ASN1_STRING *)0x0) {
        iVar6 = ASN1_INTEGER_set(p12->mac->iter,iter);
        if (iVar6 != 0) {
          pPVar1 = p12->mac;
          goto LAB_000dea84;
        }
        iVar6 = 0xaa;
      }
    }
    ERR_put_error(0x23,0x7a,0x41,"p12_mutl.c",iVar6);
  }
LAB_000deb78:
  iVar6 = 0;
  ERR_put_error(0x23,0x7b,0x6e,"p12_mutl.c",0x90);
LAB_000deb22:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}

