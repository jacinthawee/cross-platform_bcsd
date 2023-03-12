
uint buffer_ctrl(BIO *param_1,int param_2,int param_3,BIO *param_4)

{
  char cVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  bio_st *pbVar8;
  int *piVar9;
  int iVar10;
  _func_603 *p_Var11;
  int iVar12;
  _func_599 *UNRECOVERED_JUMPTABLE;
  code *pcVar13;
  undefined *puVar14;
  undefined *puVar15;
  
  puVar14 = &_gp;
  puVar15 = &_gp;
  piVar9 = (int *)param_1->ptr;
  if (param_2 == 0xc) {
    lVar2 = BIO_int_ctrl(param_4,0x75,*piVar9,0);
    if (lVar2 != 0) {
      lVar2 = BIO_int_ctrl(param_4,0x75,piVar9[1],1);
      return (uint)(lVar2 != 0);
    }
    return 0;
  }
  if (param_2 < 0xd) {
    if (param_2 == 3) {
      return piVar9[6];
    }
    if (param_2 < 4) {
      if (param_2 == 1) {
        pbVar8 = param_1->next_bio;
        piVar9[4] = 0;
        piVar9[3] = 0;
        piVar9[7] = 0;
        piVar9[6] = 0;
        goto joined_r0x00526064;
      }
    }
    else {
      if (param_2 == 10) {
        uVar3 = piVar9[3];
        goto joined_r0x00525e60;
      }
      if (param_2 == 0xb) {
        pbVar8 = param_1->next_bio;
        if (pbVar8 == (bio_st *)0x0) {
          return 0;
        }
        if (0 < piVar9[6]) {
          while( true ) {
            BIO_clear_flags(param_1,0xf);
            if (piVar9[6] < 1) break;
            uVar3 = BIO_write(param_1->next_bio,(void *)(piVar9[5] + piVar9[7]),piVar9[6]);
            BIO_copy_next_retry(param_1);
            if ((int)uVar3 < 1) {
              return uVar3;
            }
            piVar9[7] = piVar9[7] + uVar3;
            piVar9[6] = piVar9[6] - uVar3;
          }
          pbVar8 = param_1->next_bio;
          param_2 = 0xb;
          piVar9[6] = 0;
          piVar9[7] = 0;
        }
        goto code_r0x005212e8;
      }
    }
LAB_0052607c:
    pbVar8 = param_1->next_bio;
  }
  else {
    if (param_2 == 0x74) {
      if (piVar9[3] < 1) {
        return 0;
      }
      uVar3 = 0;
      pcVar7 = (char *)(piVar9[2] + piVar9[4]);
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        uVar3 = uVar3 + (cVar1 == '\n');
      } while (pcVar7 != (char *)(piVar9[2] + piVar9[3] + piVar9[4]));
      return uVar3;
    }
    if (0x74 < param_2) {
      if (param_2 == 0x75) {
        iVar4 = param_3;
        iVar12 = param_3;
        if (param_4 != (BIO *)0x0) {
          if (param_4->method == (BIO_METHOD *)0x0) {
            iVar12 = piVar9[1];
          }
          else {
            iVar4 = *piVar9;
          }
        }
        iVar10 = piVar9[5];
        iVar6 = iVar10;
        if ((iVar4 < 0x1001) || (iVar4 == *piVar9)) {
          if (iVar12 < 0x1001) {
            return 1;
          }
          iVar5 = piVar9[2];
          pcVar13 = (code *)PTR_CRYPTO_malloc_006a8108;
          if (iVar12 == piVar9[1]) goto LAB_00525f2c;
LAB_00525fcc:
          puVar14 = puVar15;
          iVar6 = (*pcVar13)(param_3,"bf_buff.c",0x168);
          if (iVar6 == 0) {
            if (piVar9[2] != iVar5) {
              (**(code **)(puVar14 + -0x7f58))(iVar5);
            }
LAB_00525ffc:
            ERR_put_error(0x20,0x72,0x41,"bf_buff.c",0x1b6);
            return 0;
          }
        }
        else {
          iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(param_3,"bf_buff.c",0x163);
          if (iVar5 == 0) goto LAB_00525ffc;
          puVar14 = puVar15;
          if ((0x1000 < iVar12) && (pcVar13 = *(code **)(puVar15 + -0x7dd8), iVar12 != piVar9[1]))
          goto LAB_00525fcc;
        }
        if (piVar9[2] == iVar5) {
          iVar10 = piVar9[5];
        }
        else {
          (**(code **)(puVar14 + -0x7f58))();
          iVar10 = piVar9[5];
          piVar9[2] = iVar5;
          piVar9[4] = 0;
          piVar9[3] = 0;
          *piVar9 = iVar4;
        }
LAB_00525f2c:
        if (iVar10 != iVar6) {
          (**(code **)(puVar14 + -0x7f58))();
          piVar9[5] = iVar6;
          piVar9[7] = 0;
          piVar9[6] = 0;
          piVar9[1] = iVar12;
        }
        return 1;
      }
      if (param_2 == 0x7a) {
        if (*piVar9 < param_3) {
          puVar14 = puVar15;
          iVar4 = (*(code *)PTR_CRYPTO_malloc_006a8108)(param_3,"bf_buff.c",0x141);
          if (iVar4 == 0) goto LAB_00525ffc;
          if (piVar9[2] != 0) {
            (**(code **)(puVar14 + -0x7f58))();
          }
          piVar9[2] = iVar4;
        }
        else {
          iVar4 = piVar9[2];
        }
        pcVar13 = *(code **)(puVar14 + -0x52ec);
        piVar9[4] = 0;
        piVar9[3] = param_3;
        (*pcVar13)(iVar4,param_4,param_3);
        return 1;
      }
      goto LAB_0052607c;
    }
    if (param_2 != 0xd) {
      if (param_2 == 0x65) {
        if (param_1->next_bio != (bio_st *)0x0) {
          BIO_clear_flags(param_1,0xf);
          uVar3 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
          BIO_copy_next_retry(param_1);
          return uVar3;
        }
        return 0;
      }
      goto LAB_0052607c;
    }
    uVar3 = piVar9[6];
joined_r0x00525e60:
    if (uVar3 != 0) {
      return uVar3;
    }
    pbVar8 = param_1->next_bio;
  }
joined_r0x00526064:
  if (pbVar8 == (bio_st *)0x0) {
    return 0;
  }
code_r0x005212e8:
  if (pbVar8 == (BIO *)0x0) {
    return 0;
  }
  if ((pbVar8->method == (BIO_METHOD *)0x0) ||
     (UNRECOVERED_JUMPTABLE = pbVar8->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
    uVar3 = 0xfffffffe;
  }
  else {
    p_Var11 = pbVar8->callback;
    if (p_Var11 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005213d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*UNRECOVERED_JUMPTABLE)(pbVar8,param_2,param_3,param_4);
      return uVar3;
    }
    uVar3 = (*p_Var11)(pbVar8,6,(char *)param_4,param_2,param_3,1);
    if (0 < (int)uVar3) {
      lVar2 = (*pbVar8->method->ctrl)(pbVar8,param_2,param_3,param_4);
      uVar3 = (*p_Var11)(pbVar8,0x86,(char *)param_4,param_2,param_3,lVar2);
    }
  }
  return uVar3;
}

