
int PKCS12_set_mac(PKCS12 *p12,char *pass,int passlen,uchar *salt,int saltlen,int iter,
                  EVP_MD *md_type)

{
  ASN1_OCTET_STRING *pAVar1;
  X509_ALGOR *pXVar2;
  PKCS12_MAC_DATA *pPVar3;
  ASN1_STRING *pAVar4;
  int iVar5;
  uchar *puVar6;
  ASN1_OBJECT *pAVar7;
  ASN1_TYPE *pAVar8;
  int in_GS_OFFSET;
  int line;
  int local_64;
  undefined local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (md_type == (EVP_MD *)0x0) {
    md_type = EVP_sha1();
  }
  pPVar3 = PKCS12_MAC_DATA_new();
  p12->mac = pPVar3;
  if (pPVar3 == (PKCS12_MAC_DATA *)0x0) {
LAB_08182fbb:
    line = 0x90;
    iVar5 = 0x6e;
  }
  else {
    if (1 < iter) {
      pAVar4 = ASN1_STRING_type_new(2);
      pPVar3->iter = pAVar4;
      if (pAVar4 == (ASN1_STRING *)0x0) {
        iVar5 = 0xa6;
      }
      else {
        iVar5 = ASN1_INTEGER_set(p12->mac->iter,iter);
        if (iVar5 != 0) {
          pPVar3 = p12->mac;
          goto LAB_08182e51;
        }
        iVar5 = 0xaa;
      }
LAB_08182fa8:
      ERR_put_error(0x23,0x7a,0x41,"p12_mutl.c",iVar5);
      goto LAB_08182fbb;
    }
LAB_08182e51:
    pAVar1 = pPVar3->salt;
    if (saltlen == 0) {
      saltlen = 8;
    }
    puVar6 = (uchar *)CRYPTO_malloc(saltlen,"p12_mutl.c",0xb0);
    pAVar1->data = puVar6;
    if (puVar6 == (uchar *)0x0) {
      iVar5 = 0xb1;
      goto LAB_08182fa8;
    }
    pAVar1 = p12->mac->salt;
    pAVar1->length = saltlen;
    if (salt == (uchar *)0x0) {
      iVar5 = RAND_bytes(pAVar1->data,saltlen);
      if (iVar5 < 1) goto LAB_08182fbb;
    }
    else {
      memcpy(pAVar1->data,salt,saltlen);
    }
    pXVar2 = p12->mac->dinfo->algor;
    iVar5 = EVP_MD_type(md_type);
    pAVar7 = OBJ_nid2obj(iVar5);
    pXVar2->algorithm = pAVar7;
    pXVar2 = p12->mac->dinfo->algor;
    pAVar8 = ASN1_TYPE_new();
    pXVar2->parameter = pAVar8;
    if (pAVar8 == (ASN1_TYPE *)0x0) {
      iVar5 = 0xbc;
      goto LAB_08182fa8;
    }
    p12->mac->dinfo->algor->parameter->type = 5;
    iVar5 = OBJ_obj2nid(p12->authsafes->type);
    if (iVar5 == 0x15) {
      iVar5 = PKCS12_gen_mac_part_0(local_60,&local_64);
      if (iVar5 != 0) {
        iVar5 = ASN1_STRING_set(p12->mac->dinfo->digest,local_60,local_64);
        if (iVar5 == 0) {
          ERR_put_error(0x23,0x7b,0x6f,"p12_mutl.c",0x98);
        }
        else {
          iVar5 = 1;
        }
        goto LAB_08182f4c;
      }
    }
    else {
      ERR_put_error(0x23,0x6b,0x79,"p12_mutl.c",0x4f);
    }
    line = 0x94;
    iVar5 = 0x6d;
  }
  ERR_put_error(0x23,0x7b,iVar5,"p12_mutl.c",line);
  iVar5 = 0;
LAB_08182f4c:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}

