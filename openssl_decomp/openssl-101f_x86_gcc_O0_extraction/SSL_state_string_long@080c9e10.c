
char * SSL_state_string_long(SSL *s)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = s->state;
  if (iVar1 == 0x2010) {
    return "SSLv2 read client hello A";
  }
  if (iVar1 < 0x2011) {
    if (iVar1 == 0x1131) {
      return "SSLv3 read server certificate B";
    }
    if (iVar1 < 0x1132) {
      if (iVar1 == 0x1053) {
        return "SSLv2 write client certificate D";
      }
      if (iVar1 < 0x1054) {
        if (iVar1 == 0x1021) {
          return "SSLv2 read server hello B";
        }
        if (iVar1 < 0x1022) {
          if (iVar1 == 0x1003) {
            return "ok/connect SSL initialization";
          }
          if (iVar1 < 0x1004) {
            if (iVar1 == 3) {
              return "SSL negotiation finished successfully";
            }
            if (iVar1 == 0x1000) {
              return "before connect initialization";
            }
          }
          else {
            if (iVar1 == 0x1011) {
              return "SSLv2 write client hello B";
            }
            if (iVar1 == 0x1020) {
              return "SSLv2 read server hello A";
            }
            if (iVar1 == 0x1010) {
              return "SSLv2 write client hello A";
            }
          }
        }
        else {
          if (iVar1 == 0x1041) {
            return "SSLv2 write client finished B";
          }
          if (iVar1 < 0x1042) {
            if (iVar1 == 0x1031) {
              return "SSLv2 write client master key B";
            }
            if (iVar1 == 0x1040) {
              return "SSLv2 write client finished A";
            }
            if (iVar1 == 0x1030) {
              return "SSLv2 write client master key A";
            }
          }
          else {
            if (iVar1 == 0x1051) {
              return "SSLv2 write client certificate B";
            }
            if (0x1051 < iVar1) {
              return "SSLv2 write client certificate C";
            }
            if (iVar1 == 0x1050) {
              return "SSLv2 write client certificate A";
            }
          }
        }
      }
      else {
        if (iVar1 == 0x1100) {
LAB_080ca725:
          return "SSLv3 flush data";
        }
        if (iVar1 < 0x1101) {
          if (iVar1 == 0x1070) {
            return "SSLv2 read server finished A";
          }
          if (iVar1 < 0x1071) {
            if (iVar1 == 0x1060) {
              return "SSLv2 read server verify A";
            }
            if (iVar1 == 0x1061) {
              return "SSLv2 read server verify B";
            }
          }
          else {
            if (iVar1 == 0x1080) {
              return "SSLv2 client start encryption";
            }
            if (iVar1 == 0x1090) {
              return "SSLv2 X509 read client certificate";
            }
            if (iVar1 == 0x1071) {
              return "SSLv2 read server finished B";
            }
          }
        }
        else {
          if (iVar1 == 0x1121) {
            return "SSLv3 read server hello B";
          }
          if (iVar1 < 0x1122) {
            if (iVar1 == 0x1111) {
              return "SSLv3 write client hello B";
            }
            if (iVar1 == 0x1120) {
              return "SSLv3 read server hello A";
            }
            if (iVar1 == 0x1110) {
              return "SSLv3 write client hello A";
            }
          }
          else {
            if (iVar1 == 0x1127) {
              return "DTLS1 read hello verify request B";
            }
            if (iVar1 == 0x1130) {
              return "SSLv3 read server certificate A";
            }
            if (iVar1 == 0x1126) {
              return "DTLS1 read hello verify request A";
            }
          }
        }
      }
    }
    else {
      if (iVar1 == 0x11a0) {
LAB_080ca743:
        return "SSLv3 write change cipher spec A";
      }
      if (iVar1 < 0x11a1) {
        if (iVar1 == 0x1170) {
          return "SSLv3 write client certificate A";
        }
        if (iVar1 < 0x1171) {
          if (iVar1 == 0x1150) {
            return "SSLv3 read server certificate request A";
          }
          if (iVar1 < 0x1151) {
            if (iVar1 == 0x1140) {
              return "SSLv3 read server key exchange A";
            }
            if (iVar1 == 0x1141) {
              return "SSLv3 read server key exchange B";
            }
          }
          else {
            if (iVar1 == 0x1160) {
              return "SSLv3 read server done A";
            }
            if (iVar1 == 0x1161) {
              return "SSLv3 read server done B";
            }
            if (iVar1 == 0x1151) {
              return "SSLv3 read server certificate request B";
            }
          }
        }
        else {
          if (iVar1 == 0x1180) {
            return "SSLv3 write client key exchange A";
          }
          if (iVar1 < 0x1181) {
            if (iVar1 == 0x1172) {
              return "SSLv3 write client certificate C";
            }
            if (iVar1 < 0x1172) {
              return "SSLv3 write client certificate B";
            }
            if (iVar1 == 0x1173) {
              return "SSLv3 write client certificate D";
            }
          }
          else {
            if (iVar1 == 0x1190) {
              return "SSLv3 write certificate verify A";
            }
            if (iVar1 == 0x1191) {
              return "SSLv3 write certificate verify B";
            }
            if (iVar1 == 0x1181) {
              return "SSLv3 write client key exchange B";
            }
          }
        }
      }
      else {
        if (iVar1 == 0x11e0) {
          return "SSLv3 read server session ticket A";
        }
        if (iVar1 < 0x11e1) {
          if (iVar1 == 0x11c0) goto LAB_080ca749;
          if (iVar1 < 0x11c1) {
            if (iVar1 == 0x11b0) goto LAB_080ca6d7;
            if (iVar1 == 0x11b1) goto LAB_080ca6e3;
            if (iVar1 == 0x11a1) goto LAB_080ca536;
          }
          else {
            if (iVar1 == 0x11d0) goto LAB_080ca6d1;
            if (iVar1 == 0x11d1) goto LAB_080ca6cb;
            if (iVar1 == 0x11c1) goto LAB_080ca576;
          }
        }
        else {
          if (iVar1 == 0x1220) {
            return "SSLv2/v3 read server hello A";
          }
          if (iVar1 < 0x1221) {
            if (iVar1 == 0x1210) {
              return "SSLv2/v3 write client hello A";
            }
            if (iVar1 == 0x1211) {
              return "SSLv2/v3 write client hello B";
            }
            if (iVar1 == 0x11e1) {
              return "SSLv3 read server session ticket B";
            }
          }
          else {
            if (iVar1 == 0x2000) {
              return "before accept initialization";
            }
            if (iVar1 == 0x2003) {
              return "ok/accept SSL initialization";
            }
            if (iVar1 == 0x1221) {
              return "SSLv2/v3 read server hello B";
            }
          }
        }
      }
    }
    goto LAB_080c9f6b;
  }
  if (iVar1 == 0x2131) {
    return "SSLv3 write server hello B";
  }
  if (iVar1 < 0x2132) {
    if (iVar1 == 0x2071) {
      return "SSLv2 write request certificate B";
    }
    if (iVar1 < 0x2072) {
      if (iVar1 == 0x2040) {
        return "SSLv2 write server verify A";
      }
      if (iVar1 < 0x2041) {
        if (iVar1 == 0x2020) {
          return "SSLv2 write server hello A";
        }
        if (iVar1 < 0x2021) {
          pcVar2 = "SSLv2 read client hello B";
          if (iVar1 != 0x2011) {
            if (iVar1 == 0x2012) {
              return "SSLv2 read client hello C";
            }
            goto LAB_080c9f6b;
          }
        }
        else {
          pcVar2 = "SSLv2 read client master key A";
          if ((iVar1 != 0x2030) && (pcVar2 = "SSLv2 read client master key B", iVar1 != 0x2031)) {
            if (iVar1 == 0x2021) {
              return "SSLv2 write server hello B";
            }
            goto LAB_080c9f6b;
          }
        }
      }
      else {
        if (iVar1 == 0x2051) {
          return "SSLv2 read client finished B";
        }
        if (iVar1 < 0x2052) {
          pcVar2 = "SSLv2 write server verify C";
          if (((iVar1 != 0x2042) && (pcVar2 = "SSLv2 write server verify B", 0x2041 < iVar1)) &&
             (pcVar2 = "SSLv2 read client finished A", iVar1 != 0x2050)) {
LAB_080c9f6b:
            return "unknown state";
          }
        }
        else {
          pcVar2 = "SSLv2 write server finished B";
          if ((iVar1 != 0x2061) && (pcVar2 = "SSLv2 write request certificate A", iVar1 != 0x2070))
          {
            if (iVar1 == 0x2060) {
              return "SSLv2 write server finished A";
            }
            goto LAB_080c9f6b;
          }
        }
      }
    }
    else {
      if (iVar1 == 0x2111) {
        return "SSLv3 read client hello B";
      }
      if (iVar1 < 0x2112) {
        if (iVar1 == 0x2080) {
          return "SSLv2 server start encryption";
        }
        if (iVar1 < 0x2081) {
          pcVar2 = "SSLv2 write request certificate C";
          if (iVar1 != 0x2072) {
            if (iVar1 == 0x2073) {
              return "SSLv2 write request certificate D";
            }
            goto LAB_080c9f6b;
          }
        }
        else {
          if (iVar1 == 0x2100) goto LAB_080ca725;
          pcVar2 = "SSLv3 read client hello A";
          if (iVar1 != 0x2110) {
            if (iVar1 == 0x2090) {
              return "SSLv2 X509 read server certificate";
            }
            goto LAB_080c9f6b;
          }
        }
      }
      else {
        if (iVar1 == 0x2120) {
          return "SSLv3 write hello request A";
        }
        if (iVar1 < 0x2121) {
          pcVar2 = "DTLS1 write hello verify request A";
          if ((iVar1 != 0x2113) && (pcVar2 = "SSLv3 read client hello C", 0x2112 < iVar1)) {
            if (iVar1 == 0x2114) {
              return "DTLS1 write hello verify request B";
            }
            goto LAB_080c9f6b;
          }
        }
        else {
          pcVar2 = "SSLv3 write hello request C";
          if ((iVar1 != 0x2122) && (pcVar2 = "SSLv3 write hello request B", 0x2121 < iVar1)) {
            if (iVar1 == 0x2130) {
              return "SSLv3 write server hello A";
            }
            goto LAB_080c9f6b;
          }
        }
      }
    }
  }
  else {
    if (iVar1 == 0x21b0) {
LAB_080ca749:
      return "SSLv3 read change cipher spec A";
    }
    if (0x21b0 < iVar1) {
      if (iVar1 == 0x21f0) {
        return "SSLv3 write session ticket A";
      }
      if (iVar1 < 0x21f1) {
        if (iVar1 == 0x21d0) goto LAB_080ca743;
        if (iVar1 < 0x21d1) {
          if (iVar1 == 0x21c0) {
LAB_080ca6d1:
            return "SSLv3 read finished A";
          }
          if (iVar1 == 0x21c1) {
LAB_080ca6cb:
            return "SSLv3 read finished B";
          }
          if (iVar1 == 0x21b1) {
LAB_080ca576:
            return "SSLv3 read change cipher spec B";
          }
        }
        else {
          if (iVar1 == 0x21e0) {
LAB_080ca6d7:
            return "SSLv3 write finished A";
          }
          if (iVar1 == 0x21e1) {
LAB_080ca6e3:
            return "SSLv3 write finished B";
          }
          if (iVar1 == 0x21d1) {
LAB_080ca536:
            return "SSLv3 write change cipher spec B";
          }
        }
      }
      else {
        if (iVar1 == 0x3004) {
          return "SSL renegotiate ciphers";
        }
        if (iVar1 < 0x3005) {
          if (iVar1 == 0x2210) {
            return "SSLv2/v3 read client hello A";
          }
          if (iVar1 == 0x2211) {
            return "SSLv2/v3 read client hello B";
          }
          if (iVar1 == 0x21f1) {
            return "SSLv3 write session ticket B";
          }
        }
        else {
          if (iVar1 == 0x5000) {
            return "before/connect initialization";
          }
          if (iVar1 == 0x6000) {
            return "before/accept initialization";
          }
          if (iVar1 == 0x4000) {
            return "before SSL initialization";
          }
        }
      }
      goto LAB_080c9f6b;
    }
    if (iVar1 == 0x2170) {
      return "SSLv3 write server done A";
    }
    if (iVar1 < 0x2171) {
      if (iVar1 == 0x2150) {
        return "SSLv3 write key exchange A";
      }
      if (iVar1 < 0x2151) {
        pcVar2 = "SSLv3 write certificate A";
        if (iVar1 != 0x2140) {
          if (iVar1 == 0x2141) {
            return "SSLv3 write certificate B";
          }
          goto LAB_080c9f6b;
        }
      }
      else {
        pcVar2 = "SSLv3 write certificate request A";
        if ((iVar1 != 0x2160) && (pcVar2 = "SSLv3 write certificate request B", iVar1 != 0x2161)) {
          if (iVar1 == 0x2151) {
            return "SSLv3 write key exchange B";
          }
          goto LAB_080c9f6b;
        }
      }
    }
    else {
      if (iVar1 == 0x2190) {
        return "SSLv3 read client key exchange A";
      }
      if (iVar1 < 0x2191) {
        pcVar2 = "SSLv3 read client certificate A";
        if ((iVar1 != 0x2180) && (pcVar2 = "SSLv3 read client certificate B", iVar1 != 0x2181)) {
          if (iVar1 == 0x2171) {
            return "SSLv3 write server done B";
          }
          goto LAB_080c9f6b;
        }
      }
      else {
        pcVar2 = "SSLv3 read certificate verify A";
        if ((iVar1 != 0x21a0) && (pcVar2 = "SSLv3 read certificate verify B", iVar1 != 0x21a1)) {
          if (iVar1 == 0x2191) {
            return "SSLv3 read client key exchange B";
          }
          goto LAB_080c9f6b;
        }
      }
    }
  }
  return pcVar2;
}

