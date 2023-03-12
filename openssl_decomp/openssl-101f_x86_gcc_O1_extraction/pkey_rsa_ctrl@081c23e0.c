
undefined4 pkey_rsa_ctrl(int param_1,int param_2,int param_3,EVP_MD *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  EVP_MD *pEVar3;
  int in_GS_OFFSET;
  int iVar4;
  int line;
  X509_ALGOR *local_18;
  ASN1_OBJECT *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  piVar1 = *(int **)(param_1 + 0x14);
  if (param_2 != 0xb) {
    if (0xb < param_2) {
      if (param_2 == 0x1004) {
        if (param_4 != (EVP_MD *)0x0) {
          piVar1[1] = (int)param_4;
          uVar2 = 1;
          goto LAB_081c2509;
        }
LAB_081c25b9:
        uVar2 = 0xfffffffe;
      }
      else {
        if (param_2 < 0x1005) {
          if (param_2 == 0x1002) {
LAB_081c2580:
            if (piVar1[4] != 6) {
              line = 0x1ff;
              iVar4 = 0x92;
              goto LAB_081c24ce;
            }
            if (param_2 == 0x1007) {
              param_4->type = piVar1[7];
              uVar2 = 1;
              goto LAB_081c2509;
            }
            if (-3 < param_3) {
              piVar1[7] = param_3;
              uVar2 = 1;
              goto LAB_081c2509;
            }
            goto LAB_081c25b9;
          }
          if (0x1002 < param_2) {
            if (0xff < param_3) {
              *piVar1 = param_3;
              uVar2 = 1;
              goto LAB_081c2509;
            }
            line = 0x20f;
            iVar4 = 0x91;
            goto LAB_081c24ce;
          }
          if (param_2 != 0x1001) goto LAB_081c25b9;
          if (5 < param_3 - 1U) goto LAB_081c268a;
          pEVar3 = (EVP_MD *)piVar1[5];
          if (pEVar3 != (EVP_MD *)0x0) {
            if (param_3 == 3) goto LAB_081c26c0;
            if (param_3 != 5) goto LAB_081c246a;
            iVar4 = EVP_MD_type(pEVar3);
            iVar4 = RSA_X931_hash_id(iVar4);
            if (iVar4 == -1) goto LAB_081c270d;
LAB_081c2491:
            piVar1[4] = param_3;
            uVar2 = 1;
            goto LAB_081c2509;
          }
LAB_081c246a:
          if (param_3 == 6) {
            if ((*(byte *)(param_1 + 0x10) & 0x18) != 0) {
LAB_081c2489:
              if (pEVar3 == (EVP_MD *)0x0) {
                pEVar3 = EVP_sha1();
                piVar1[5] = (int)pEVar3;
              }
              goto LAB_081c2491;
            }
          }
          else {
            if (param_3 != 4) goto LAB_081c2491;
            if ((*(uint *)(param_1 + 0x10) & 0x300) != 0) goto LAB_081c2489;
          }
LAB_081c268a:
          line = 500;
          iVar4 = 0x90;
        }
        else {
          if (param_2 == 0x1006) {
            param_4->type = piVar1[4];
            uVar2 = 1;
            goto LAB_081c2509;
          }
          if (0x1005 < param_2) {
            if (param_2 == 0x1007) goto LAB_081c2580;
            if (param_2 != 0x1008) goto LAB_081c25b9;
          }
          if (piVar1[4] == 6) {
            if (param_2 != 0x1008) {
              piVar1[6] = (int)param_4;
              uVar2 = 1;
              goto LAB_081c2509;
            }
            if (piVar1[6] == 0) {
              param_4->type = piVar1[5];
            }
            else {
              param_4->type = piVar1[6];
            }
            goto LAB_081c2504;
          }
          line = 0x225;
          iVar4 = 0x9c;
        }
LAB_081c24ce:
        ERR_put_error(4,0x8f,iVar4,"rsa_pmeth.c",line);
        uVar2 = 0xfffffffe;
      }
      goto LAB_081c2509;
    }
    if (param_2 < 6) {
      if (param_2 < 3) {
        if (param_2 != 1) {
          if (param_2 != 2) goto LAB_081c25b9;
          line = 0x24a;
          iVar4 = 0x94;
          goto LAB_081c24ce;
        }
        if (param_4 != (EVP_MD *)0x0) {
          if (piVar1[4] == 3) {
LAB_081c26c0:
            ERR_put_error(4,0x8c,0x8d,"rsa_pmeth.c",0x1c3);
            uVar2 = 0;
            goto LAB_081c2509;
          }
          if (piVar1[4] == 5) {
            iVar4 = EVP_MD_type(param_4);
            iVar4 = RSA_X931_hash_id(iVar4);
            if (iVar4 == -1) {
LAB_081c270d:
              ERR_put_error(4,0x8c,0x8e,"rsa_pmeth.c",0x1cc);
              uVar2 = 0;
              goto LAB_081c2509;
            }
          }
        }
        piVar1[5] = (int)param_4;
      }
    }
    else if (param_2 != 9) {
      if (param_2 < 10) {
        if (param_2 != 7) goto LAB_081c25b9;
      }
      else {
        local_18 = (X509_ALGOR *)0x0;
        local_14 = (ASN1_OBJECT *)0x0;
        if (param_4 != (EVP_MD *)0x0) {
          CMS_RecipientInfo_ktri_get0_algs
                    ((CMS_RecipientInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,&local_18);
          if (local_18 != (X509_ALGOR *)0x0) {
            X509_ALGOR_get0(&local_14,(int *)0x0,(void **)0x0,local_18);
          }
          if ((local_14 != (ASN1_OBJECT *)0x0) && (iVar4 = OBJ_obj2nid(local_14), iVar4 == 0x397)) {
            piVar1[4] = 4;
          }
        }
      }
    }
  }
LAB_081c2504:
  uVar2 = 1;
LAB_081c2509:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

