
uint * TS_REQ_to_TS_VERIFY_CTX(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint *puVar5;
  
  if (param_1 == 0) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("ts_verify_ctx.c",0x76,"req != NULL");
    if (param_2 == (uint *)0x0) goto LAB_005c757c;
LAB_005c7298:
    (*(code *)PTR_X509_STORE_free_006a8384)(param_2[1]);
    (*(code *)PTR_sk_pop_free_006a8158)(param_2[2],PTR_X509_free_006a7f90);
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(param_2[3]);
    (*(code *)PTR_X509_ALGOR_free_006a8f94)(param_2[4]);
    (*(code *)PTR_CRYPTO_free_006a7f88)(param_2[5]);
    (*(code *)PTR_BIO_free_all_006a7f74)(param_2[7]);
    (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(param_2[8]);
    (*(code *)PTR_GENERAL_NAME_free_006a84a4)(param_2[9]);
    (*(code *)PTR_memset_006aab00)(param_2,0,0x28);
    puVar5 = param_2;
  }
  else {
    if (param_2 != (uint *)0x0) goto LAB_005c7298;
LAB_005c757c:
    puVar5 = (uint *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"ts_verify_ctx.c",0x42);
    if (puVar5 == (uint *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x90,0x41,"ts_verify_ctx.c",0x46);
      return (uint *)0x0;
    }
    (*(code *)PTR_memset_006aab00)(puVar5,0,0x28);
  }
  *puVar5 = 0x6e;
  iVar1 = TS_REQ_get_policy_id(param_1);
  if (iVar1 == 0) {
    *puVar5 = *puVar5 & 0xfffffffb;
  }
  else {
    uVar2 = (*(code *)PTR_OBJ_dup_006a95b4)(iVar1);
    puVar5[3] = uVar2;
    if (uVar2 == 0) goto LAB_005c7470;
  }
  uVar3 = TS_REQ_get_msg_imprint(param_1);
  uVar4 = TS_MSG_IMPRINT_get_algo(uVar3);
  uVar2 = (*(code *)PTR_X509_ALGOR_dup_006aa514)(uVar4);
  puVar5[4] = uVar2;
  if (uVar2 != 0) {
    uVar3 = TS_MSG_IMPRINT_get_msg(uVar3);
    uVar2 = (*(code *)PTR_ASN1_STRING_length_006a842c)(uVar3);
    puVar5[6] = uVar2;
    uVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar2,"ts_verify_ctx.c",0x8d);
    puVar5[5] = uVar2;
    if (uVar2 != 0) {
      uVar3 = (*(code *)PTR_ASN1_STRING_data_006a8430)(uVar3);
      (*(code *)PTR_memcpy_006aabf4)(uVar2,uVar3,puVar5[6]);
      iVar1 = TS_REQ_get_nonce(param_1);
      if (iVar1 == 0) {
        *puVar5 = *puVar5 & 0xffffffdf;
      }
      else {
        uVar2 = (*(code *)PTR_ASN1_INTEGER_dup_006aa37c)(iVar1);
        puVar5[8] = uVar2;
        if (uVar2 == 0) goto LAB_005c7470;
      }
      return puVar5;
    }
  }
LAB_005c7470:
  if (param_2 == (uint *)0x0) {
    (*(code *)PTR_X509_STORE_free_006a8384)(puVar5[1]);
    (*(code *)PTR_sk_pop_free_006a8158)(puVar5[2],PTR_X509_free_006a7f90);
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(puVar5[3]);
    (*(code *)PTR_X509_ALGOR_free_006a8f94)(puVar5[4]);
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar5[5]);
    (*(code *)PTR_BIO_free_all_006a7f74)(puVar5[7]);
    (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(puVar5[8]);
    (*(code *)PTR_GENERAL_NAME_free_006a84a4)(puVar5[9]);
    (*(code *)PTR_memset_006aab00)(puVar5,0,0x28);
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar5);
    return (uint *)0x0;
  }
  (*(code *)PTR_X509_STORE_free_006a8384)(param_2[1]);
  (*(code *)PTR_sk_pop_free_006a8158)(param_2[2],PTR_X509_free_006a7f90);
  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(param_2[3]);
  (*(code *)PTR_X509_ALGOR_free_006a8f94)(param_2[4]);
  (*(code *)PTR_CRYPTO_free_006a7f88)(param_2[5]);
  (*(code *)PTR_BIO_free_all_006a7f74)(param_2[7]);
  (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(param_2[8]);
  (*(code *)PTR_GENERAL_NAME_free_006a84a4)(param_2[9]);
  (*(code *)PTR_memset_006aab00)(param_2,0,0x28);
  return (uint *)0x0;
}

