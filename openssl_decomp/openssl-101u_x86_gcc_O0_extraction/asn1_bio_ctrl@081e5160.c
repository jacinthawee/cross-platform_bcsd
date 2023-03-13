
long asn1_bio_ctrl(bio_st *param_1,int param_2,long param_3,int *param_4)

{
  _func_599 *UNRECOVERED_JUMPTABLE;
  _func_603 *p_Var1;
  int *piVar2;
  code *pcVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  
  piVar2 = (int *)param_1->ptr;
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  if (param_2 == 0x97) {
    piVar2[10] = *param_4;
    piVar2[0xb] = param_4[1];
    return 1;
  }
  if (param_2 < 0x98) {
    if (param_2 == 0x95) {
      piVar2[8] = *param_4;
      piVar2[9] = param_4[1];
      return 1;
    }
    if (0x95 < param_2) {
      *param_4 = piVar2[8];
      param_4[1] = piVar2[9];
      return 1;
    }
    if (param_2 == 0xb) {
      if (param_1->next_bio == (bio_st *)0x0) {
        return 0;
      }
      iVar6 = *piVar2;
      if (iVar6 == 2) {
        if (((code *)piVar2[10] != (code *)0x0) &&
           (iVar6 = (*(code *)piVar2[10])(param_1,piVar2 + 0xc,piVar2 + 0xd,piVar2 + 0xf),
           iVar6 == 0)) goto LAB_081e51fa;
        iVar6 = (piVar2[0xd] < 1) + 5;
        *piVar2 = iVar6;
      }
      if (iVar6 == 5) {
        iVar6 = piVar2[0xd];
        if (iVar6 < 1) goto LAB_081e51fa;
        pcVar3 = (code *)piVar2[0xb];
        iVar5 = piVar2[0xe];
        while( true ) {
          iVar5 = BIO_write(param_1->next_bio,(void *)(iVar5 + piVar2[0xc]),iVar6);
          if (iVar5 < 1) {
            return iVar5;
          }
          iVar6 = piVar2[0xd] - iVar5;
          piVar2[0xd] = iVar6;
          if (iVar6 < 1) break;
          iVar5 = iVar5 + piVar2[0xe];
          piVar2[0xe] = iVar5;
        }
        if (pcVar3 != (code *)0x0) {
          (*pcVar3)(param_1,piVar2 + 0xc,piVar2 + 0xd,piVar2 + 0xf);
        }
        *piVar2 = 6;
        piVar2[0xe] = 0;
      }
      else if (iVar6 != 6) {
LAB_081e51fa:
        BIO_clear_flags(param_1,0xf);
        return 0;
      }
      param_2 = 0xb;
      param_1 = param_1->next_bio;
      goto BIO_ctrl;
    }
  }
  else {
    if (param_2 == 0x99) {
      piVar2[0xf] = (int)param_4;
      return 1;
    }
    if (param_2 < 0x99) {
      *param_4 = piVar2[10];
      param_4[1] = piVar2[0xb];
      return 1;
    }
    if (param_2 == 0x9a) {
      *param_4 = piVar2[0xf];
      return 1;
    }
  }
  param_1 = param_1->next_bio;
  if (param_1 == (bio_st *)0x0) {
    return 0;
  }
BIO_ctrl:
  if (param_1 == (bio_st *)0x0) {
    return 0;
  }
  if ((param_1->method == (BIO_METHOD *)0x0) ||
     (UNRECOVERED_JUMPTABLE = param_1->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x15d);
    lVar4 = -2;
  }
  else {
    p_Var1 = param_1->callback;
    if (p_Var1 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08116477. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      lVar4 = (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
      return lVar4;
    }
    lVar4 = (*p_Var1)(param_1,6,(char *)param_4,param_2,param_3,1);
    if (0 < lVar4) {
      lVar4 = (*param_1->method->ctrl)(param_1,param_2,param_3,param_4);
      lVar4 = (*p_Var1)(param_1,0x86,(char *)param_4,param_2,param_3,lVar4);
    }
  }
  return lVar4;
}

