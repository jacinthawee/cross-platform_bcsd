
EVP_PKEY * EVP_PKCS82PKEY(PKCS8_PRIV_KEY_INFO *p8)

{
  undefined *puVar1;
  int iVar2;
  EVP_PKEY *pEVar3;
  int iVar4;
  code *pcVar5;
  double in_f12_13;
  ASN1_OBJECT *local_68;
  char acStack_64 [80];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_PKCS8_pkey_get0_006a98c0)(&local_68,0,0,0,p8);
  if (iVar2 == 0) {
    pEVar3 = (EVP_PKEY *)0x0;
  }
  else {
    pEVar3 = EVP_PKEY_new();
    if (pEVar3 == (EVP_PKEY *)0x0) {
      ERR_put_error(6,0x6f,0x41,"evp_pkey.c",0x4e);
      pEVar3 = (EVP_PKEY *)0x0;
    }
    else {
      iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(local_68);
      iVar2 = EVP_PKEY_set_type(pEVar3,iVar2);
      if (iVar2 == 0) {
        ERR_put_error(6,0x6f,0x76,"evp_pkey.c",0x54);
        i2t_ASN1_OBJECT(acStack_64,0x50,local_68);
        ERR_add_error_data(2,&DAT_00669e14,acStack_64);
      }
      else {
        if (*(code **)(pEVar3->ameth + 0x24) == (code *)0x0) {
          iVar4 = 0x90;
          iVar2 = 0x65;
        }
        else {
          iVar2 = (**(code **)(pEVar3->ameth + 0x24))(pEVar3,p8);
          if (iVar2 != 0) goto LAB_00545e0c;
          iVar4 = 0x91;
          iVar2 = 0x5f;
        }
        ERR_put_error(6,0x6f,iVar4,"evp_pkey.c",iVar2);
      }
      EVP_PKEY_free(pEVar3);
      pEVar3 = (EVP_PKEY *)0x0;
    }
  }
LAB_00545e0c:
  if (local_14 == *(int *)puVar1) {
    return pEVar3;
  }
  iVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pEVar3 = (EVP_PKEY *)(*(code *)PTR_PKCS8_PRIV_KEY_INFO_new_006a9d68)();
  if (pEVar3 == (EVP_PKEY *)0x0) {
    ERR_put_error(6,0x71,0x41,"evp_pkey.c",0x7c);
    return (EVP_PKEY *)0x0;
  }
  iVar4 = *(int *)(iVar2 + 0xc);
  pEVar3->type = 0;
  if (iVar4 == 0) {
    iVar4 = 0x76;
    iVar2 = 0x96;
  }
  else {
    pcVar5 = *(code **)(iVar4 + 0x28);
    if (pcVar5 == (code *)0x0) {
      iVar4 = 0x90;
      iVar2 = 0x8f;
    }
    else {
      iVar2 = (*pcVar5)(pEVar3,iVar2);
      if (iVar2 != 0) {
        RAND_add((void *)(*(int **)(pEVar3->ameth + 4))[2],**(int **)(pEVar3->ameth + 4),in_f12_13);
        return pEVar3;
      }
      iVar4 = 0x92;
      iVar2 = 0x88;
    }
  }
  ERR_put_error(6,0x71,iVar4,"evp_pkey.c",iVar2);
  (*(code *)PTR_PKCS8_PRIV_KEY_INFO_free_006a8340)(pEVar3);
  return (EVP_PKEY *)0x0;
}

