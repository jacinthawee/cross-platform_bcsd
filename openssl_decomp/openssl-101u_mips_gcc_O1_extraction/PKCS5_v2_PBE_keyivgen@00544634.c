
int PKCS5_v2_PBE_keyivgen
              (EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,EVP_CIPHER *cipher,
              EVP_MD *md,int en_de)

{
  undefined *puVar1;
  ASN1_STRING *pAVar2;
  int iVar3;
  undefined4 uVar4;
  char *name;
  EVP_CIPHER *cipher_00;
  int reason;
  int *piVar5;
  int iVar6;
  uchar *local_28;
  int **local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int ***)PTR___stack_chk_guard_006a9ae8;
  if (((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) ||
     (pAVar2 = (param->value).asn1_string, pAVar2 == (ASN1_STRING *)0x0)) {
    pass = &DAT_00000076;
    iVar6 = 0;
    ERR_put_error(6,0x76,0x72,(char *)&DAT_006693d4,0xcb);
    piVar5 = (int *)0x0;
    goto LAB_005446bc;
  }
  local_28 = pAVar2->data;
  piVar5 = (int *)(*(code *)PTR_d2i_PBE2PARAM_006a8c88)(0,&local_28,pAVar2->length);
  if (piVar5 == (int *)0x0) {
    reason = 0x72;
    iVar3 = 0xd2;
  }
  else {
    iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)*piVar5);
    if (iVar3 == 0x45) {
      uVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)piVar5[1]);
      name = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)(uVar4);
      cipher_00 = EVP_get_cipherbyname(name);
      if (cipher_00 == (EVP_CIPHER *)0x0) {
        reason = 0x6b;
        iVar3 = 0xe5;
      }
      else {
        iVar3 = EVP_CipherInit_ex(ctx,cipher_00,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,en_de);
        if (iVar3 == 0) {
          iVar6 = 0;
          pass = (char *)cipher_00;
          goto LAB_005446bc;
        }
        iVar3 = EVP_CIPHER_asn1_to_param(ctx,*(ASN1_TYPE **)(piVar5[1] + 4));
        if (-1 < iVar3) {
          iVar6 = PKCS5_v2_PBKDF2_keyivgen
                            (ctx,pass,passlen,*(undefined4 *)(*piVar5 + 4),cipher,md,en_de);
          goto LAB_005446bc;
        }
        reason = 0x7a;
        iVar3 = 0xed;
      }
    }
    else {
      reason = 0x7c;
      iVar3 = 0xda;
    }
  }
  pass = &DAT_00000076;
  iVar6 = 0;
  ERR_put_error(6,0x76,reason,(char *)&DAT_006693d4,iVar3);
LAB_005446bc:
  (*(code *)PTR_PBE2PARAM_free_006a8c84)(piVar5);
  if (local_24 == *(int ***)puVar1) {
    return iVar6;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return **local_24 - *(int *)*(int *)pass;
}

