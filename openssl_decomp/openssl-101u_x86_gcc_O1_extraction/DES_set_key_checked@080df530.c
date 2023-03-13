
int DES_set_key_checked(const_DES_cblock *key,DES_key_schedule *schedule)

{
  int iVar1;
  
  if ((((((*key)[0] == odd_parity[(*key)[0]]) && ((*key)[1] == odd_parity[(*key)[1]])) &&
       ((*key)[2] == odd_parity[(*key)[2]])) &&
      (((*key)[3] == odd_parity[(*key)[3]] && ((*key)[4] == odd_parity[(*key)[4]])))) &&
     (((*key)[5] == odd_parity[(*key)[5]] &&
      (((*key)[6] == odd_parity[(*key)[6]] && ((*key)[7] == odd_parity[(*key)[7]])))))) {
    iVar1 = memcmp(weak_keys,key,8);
    if (iVar1 != 0) {
      iVar1 = memcmp(weak_keys + 8,key,8);
      if (iVar1 != 0) {
        iVar1 = memcmp(weak_keys + 0x10,key,8);
        if (iVar1 != 0) {
          iVar1 = memcmp(weak_keys + 0x18,key,8);
          if (iVar1 != 0) {
            iVar1 = memcmp(weak_keys + 0x20,key,8);
            if (iVar1 != 0) {
              iVar1 = memcmp(weak_keys + 0x28,key,8);
              if (iVar1 != 0) {
                iVar1 = memcmp(weak_keys + 0x30,key,8);
                if (iVar1 != 0) {
                  iVar1 = memcmp(weak_keys + 0x38,key,8);
                  if (iVar1 != 0) {
                    iVar1 = memcmp(weak_keys + 0x40,key,8);
                    if (iVar1 != 0) {
                      iVar1 = memcmp(weak_keys + 0x48,key,8);
                      if (iVar1 != 0) {
                        iVar1 = memcmp(weak_keys + 0x50,key,8);
                        if (iVar1 != 0) {
                          iVar1 = memcmp(weak_keys + 0x58,key,8);
                          if (iVar1 != 0) {
                            iVar1 = memcmp(weak_keys + 0x60,key,8);
                            if (iVar1 != 0) {
                              iVar1 = memcmp(weak_keys + 0x68,key,8);
                              if (iVar1 != 0) {
                                iVar1 = memcmp(weak_keys + 0x70,key,8);
                                if (iVar1 != 0) {
                                  iVar1 = memcmp(weak_keys + 0x78,key,8);
                                  if (iVar1 != 0) {
                                    DES_set_key_unchecked(key,schedule);
                                    return 0;
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
      }
    }
    return -2;
  }
  return -1;
}

