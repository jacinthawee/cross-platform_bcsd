
undefined4 pkey_rsa_ctrl(int param_1,int param_2,int param_3,EVP_MD *param_4)

{
  uint uVar1;
  int iVar2;
  EVP_MD *pEVar3;
  int iVar4;
  int *piVar5;
  X509_ALGOR *local_18;
  ASN1_OBJECT *local_14 [2];
  
  piVar5 = *(int **)(param_1 + 0x14);
  if (param_2 == 0xb) {
    return 1;
  }
  if (param_2 < 0xc) {
    if (5 < param_2) {
      if (param_2 == 9) {
        return 1;
      }
      if (param_2 < 10) {
        if (param_2 == 7) {
          return 1;
        }
        return 0xfffffffe;
      }
      local_18 = (X509_ALGOR *)0x0;
      local_14[0] = (ASN1_OBJECT *)0x0;
      if (param_4 == (EVP_MD *)0x0) {
        return 1;
      }
      CMS_RecipientInfo_ktri_get0_algs
                ((CMS_RecipientInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,&local_18);
      if (local_18 != (X509_ALGOR *)0x0) {
        X509_ALGOR_get0(local_14,(int *)0x0,(void **)0x0,local_18);
      }
      if (local_14[0] == (ASN1_OBJECT *)0x0) {
        return 1;
      }
      iVar2 = OBJ_obj2nid(local_14[0]);
      iVar4 = 0x397;
      if (iVar2 == 0x397) {
        iVar4 = 4;
      }
      if (iVar2 != 0x397) {
        return 1;
      }
      piVar5[4] = iVar4;
      return 1;
    }
    if (2 < param_2) {
      return 1;
    }
    if (param_2 != 1) {
      if (param_2 != 2) {
        return 0xfffffffe;
      }
      ERR_put_error(4,0x8f,0x94,"rsa_pmeth.c",0x24a);
      return 0xfffffffe;
    }
    if (param_4 != (EVP_MD *)0x0) {
      if (piVar5[4] == 3) {
LAB_00108844:
        ERR_put_error(4,0x8c,0x8d,"rsa_pmeth.c",0x1c3);
        return 0;
      }
      if (piVar5[4] == 5) {
        iVar2 = EVP_MD_type(param_4);
        iVar2 = RSA_X931_hash_id(iVar2);
        if (iVar2 == -1) {
LAB_00108874:
          ERR_put_error(4,0x8c,0x8e,"rsa_pmeth.c",0x1cc);
          return 0;
        }
      }
    }
    piVar5[5] = (int)param_4;
    return 1;
  }
  if (param_2 == 0x1004) {
    if (param_4 == (EVP_MD *)0x0) {
      return 0xfffffffe;
    }
    piVar5[1] = (int)param_4;
    return 1;
  }
  if (0x1004 < param_2) {
    if (param_2 == 0x1006) {
      param_4->type = piVar5[4];
      return 1;
    }
    if (0x1005 < param_2) {
      if (param_2 == 0x1007) goto LAB_00108784;
      if (param_2 != 0x1008) {
        return 0xfffffffe;
      }
    }
    if (piVar5[4] != 6) {
      ERR_put_error(4,0x8f,0x9c,"rsa_pmeth.c",0x225);
      return 0xfffffffe;
    }
    if (param_2 != 0x1008) {
      piVar5[6] = (int)param_4;
      return 1;
    }
    if (piVar5[6] == 0) {
      param_4->type = piVar5[5];
      return 1;
    }
    param_4->type = piVar5[6];
    return 1;
  }
  if (param_2 == 0x1002) {
LAB_00108784:
    if (piVar5[4] != 6) {
      ERR_put_error(4,0x8f,0x92,"rsa_pmeth.c",0x1ff);
      return 0xfffffffe;
    }
    if (param_2 != 0x1007) {
      if (param_3 + 2 < 0 != SCARRY4(param_3,2)) {
        return 0xfffffffe;
      }
      piVar5[7] = param_3;
      return 1;
    }
    param_4->type = piVar5[7];
    return 1;
  }
  if (0x1002 < param_2) {
    if (0xff < param_3) {
      *piVar5 = param_3;
      return 1;
    }
    ERR_put_error(4,0x8f,0x91,"rsa_pmeth.c",0x20f);
    return 0xfffffffe;
  }
  if (param_2 != 0x1001) {
    return 0xfffffffe;
  }
  if (param_3 - 1U < 6) {
    pEVar3 = (EVP_MD *)piVar5[5];
    if (pEVar3 != (EVP_MD *)0x0) {
      if (param_3 == 3) goto LAB_00108844;
      if (param_3 == 5) {
        iVar2 = EVP_MD_type(pEVar3);
        iVar2 = RSA_X931_hash_id(iVar2);
        if (iVar2 == -1) goto LAB_00108874;
        goto LAB_001086f0;
      }
    }
    if (param_3 == 6) {
      uVar1 = *(uint *)(param_1 + 0x10) & 0x18;
    }
    else {
      if (param_3 != 4) goto LAB_001086f0;
      uVar1 = *(uint *)(param_1 + 0x10) & 0x300;
    }
    if (uVar1 != 0) {
      if (pEVar3 == (EVP_MD *)0x0) {
        pEVar3 = EVP_sha1();
        piVar5[5] = (int)pEVar3;
      }
LAB_001086f0:
      piVar5[4] = param_3;
      return 1;
    }
  }
  ERR_put_error(4,0x8f,0x90,"rsa_pmeth.c",500);
  return 0xfffffffe;
}

