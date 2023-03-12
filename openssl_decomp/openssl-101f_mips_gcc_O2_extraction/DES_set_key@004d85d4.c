
int DES_set_key(const_DES_cblock *key,DES_key_schedule *schedule)

{
  int iVar1;
  
  if (_shadow_DES_check_key == 0) {
LAB_004d8604:
    DES_set_key_unchecked(key,schedule);
    return 0;
  }
  if ((((((uint)(byte)odd_parity[(*key)[0]] != (uint)(*key)[0]) ||
        ((uint)(byte)odd_parity[(*key)[1]] != (uint)(*key)[1])) ||
       ((uint)(byte)odd_parity[(*key)[2]] != (uint)(*key)[2])) ||
      (((uint)(byte)odd_parity[(*key)[3]] != (uint)(*key)[3] ||
       ((uint)(byte)odd_parity[(*key)[4]] != (uint)(*key)[4])))) ||
     (((uint)(byte)odd_parity[(*key)[5]] != (uint)(*key)[5] ||
      (((uint)(byte)odd_parity[(*key)[6]] != (uint)(*key)[6] ||
       ((uint)(byte)odd_parity[(*key)[7]] != (uint)(*key)[7])))))) {
    return -1;
  }
  iVar1 = (*(code *)PTR_memcmp_006aabd8)(weak_keys,key,8);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8b8,key,8);
    if (iVar1 != 0) {
      iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8c0,key,8);
      if (iVar1 != 0) {
        iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8c8,key,8);
        if (iVar1 != 0) {
          iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8d0,key,8);
          if (iVar1 != 0) {
            iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8d8,key,8);
            if (iVar1 != 0) {
              iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8e0,key,8);
              if (iVar1 != 0) {
                iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8e8,key,8);
                if (iVar1 != 0) {
                  iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8f0,key,8);
                  if (iVar1 != 0) {
                    iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8f8,key,8);
                    if (iVar1 != 0) {
                      iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b900,key,8);
                      if (iVar1 != 0) {
                        iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b908,key,8);
                        if (iVar1 != 0) {
                          iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b910,key,8);
                          if (iVar1 != 0) {
                            iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b918,key,8);
                            if (iVar1 != 0) {
                              iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b920,key,8);
                              if ((iVar1 != 0) &&
                                 (iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b928,key,8), iVar1 != 0
                                 )) goto LAB_004d8604;
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
        }
      }
    }
  }
  return -2;
}

