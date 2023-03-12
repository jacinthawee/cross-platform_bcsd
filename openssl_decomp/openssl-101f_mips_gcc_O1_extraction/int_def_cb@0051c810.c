
undefined4 int_def_cb(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_1,"ALL",param_2);
  if (iVar1 == 0) {
    uVar2 = 1;
    *param_3 = *param_3 | 0xffff;
  }
  else {
    iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_1,"RSA",param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 1;
      return 1;
    }
    iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_1,"DSA",param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 2;
      return 1;
    }
    iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_1,&DAT_0064855c,param_2);
    if (iVar1 == 0) {
      uVar2 = 1;
      *param_3 = *param_3 | 0x10;
    }
    else {
      iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_1,"ECDSA",param_2);
      if (iVar1 == 0) {
        uVar2 = 1;
        *param_3 = *param_3 | 0x20;
      }
      else {
        iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_1,"DH",param_2);
        if (iVar1 == 0) {
          uVar2 = 1;
          *param_3 = *param_3 | 4;
        }
        else {
          iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_1,"RAND",param_2);
          if (iVar1 == 0) {
            uVar2 = 1;
            *param_3 = *param_3 | 8;
          }
          else {
            iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_1,"CIPHERS",param_2);
            if (iVar1 == 0) {
              uVar2 = 1;
              *param_3 = *param_3 | 0x40;
            }
            else {
              iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_1,"DIGESTS",param_2);
              if (iVar1 == 0) {
                uVar2 = 1;
                *param_3 = *param_3 | 0x80;
              }
              else {
                iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_1,"PKEY",param_2);
                if (iVar1 == 0) {
                  uVar2 = 1;
                  *param_3 = *param_3 | 0x600;
                }
                else {
                  iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_1,"PKEY_CRYPTO",param_2);
                  if (iVar1 == 0) {
                    uVar2 = 1;
                    *param_3 = *param_3 | 0x200;
                  }
                  else {
                    iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_1,"PKEY_ASN1",param_2);
                    if (iVar1 == 0) {
                      uVar2 = 1;
                      *param_3 = *param_3 | 0x400;
                    }
                    else {
                      uVar2 = 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}

