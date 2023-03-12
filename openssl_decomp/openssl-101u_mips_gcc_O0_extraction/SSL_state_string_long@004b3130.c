
char * SSL_state_string_long(SSL *s)

{
  int iVar1;
  
  iVar1 = s->state;
  if (iVar1 == 0x2000) {
    return "before accept initialization";
  }
  if (iVar1 < 0x2001) {
    if (iVar1 == 0x1171) {
      return "SSLv3 write client certificate B";
    }
    if (iVar1 < 0x1172) {
      if (iVar1 == 0x1126) {
        return "DTLS1 read hello verify request A";
      }
      if (iVar1 < 0x1127) {
        if (iVar1 == 0x1100) {
          return "SSLv3 flush data";
        }
        if (iVar1 < 0x1101) {
          if (iVar1 == 5) {
            return "error";
          }
          if (iVar1 < 6) {
            if (iVar1 == 3) {
              return "SSL negotiation finished successfully";
            }
          }
          else {
            if (iVar1 == 0x1000) {
              return "before connect initialization";
            }
            if (iVar1 == 0x1003) {
              return "ok/connect SSL initialization";
            }
          }
        }
        else {
          if (iVar1 == 0x1111) {
            return "SSLv3 write client hello B";
          }
          if (iVar1 < 0x1112) {
            if (iVar1 == 0x1110) {
              return "SSLv3 write client hello A";
            }
          }
          else {
            if (iVar1 == 0x1120) {
              return "SSLv3 read server hello A";
            }
            if (iVar1 == 0x1121) {
              return "SSLv3 read server hello B";
            }
          }
        }
      }
      else {
        if (iVar1 == 0x1141) {
          return "SSLv3 read server key exchange B";
        }
        if (iVar1 < 0x1142) {
          if (iVar1 == 0x1130) {
            return "SSLv3 read server certificate A";
          }
          if (iVar1 < 0x1131) {
            if (iVar1 == 0x1127) {
              return "DTLS1 read hello verify request B";
            }
          }
          else {
            if (iVar1 == 0x1131) {
              return "SSLv3 read server certificate B";
            }
            if (iVar1 == 0x1140) {
              return "SSLv3 read server key exchange A";
            }
          }
        }
        else {
          if (iVar1 == 0x1160) {
            return "SSLv3 read server done A";
          }
          if (iVar1 < 0x1161) {
            if (iVar1 == 0x1150) {
              return "SSLv3 read server certificate request A";
            }
            if (iVar1 == 0x1151) {
              return "SSLv3 read server certificate request B";
            }
          }
          else {
            if (iVar1 == 0x1161) {
              return "SSLv3 read server done B";
            }
            if (iVar1 == 0x1170) {
              return "SSLv3 write client certificate A";
            }
          }
        }
      }
    }
    else {
      if (iVar1 == 0x11b1) {
        return "SSLv3 write finished B";
      }
      if (iVar1 < 0x11b2) {
        if (iVar1 == 0x1190) {
          return "SSLv3 write certificate verify A";
        }
        if (iVar1 < 0x1191) {
          if (iVar1 == 0x1173) {
            return "SSLv3 write client certificate D";
          }
          if (iVar1 < 0x1173) {
            return "SSLv3 write client certificate C";
          }
          if (iVar1 == 0x1180) {
            return "SSLv3 write client key exchange A";
          }
          if (iVar1 == 0x1181) {
            return "SSLv3 write client key exchange B";
          }
        }
        else {
          if (iVar1 == 0x11a0) {
            return "SSLv3 write change cipher spec A";
          }
          if (iVar1 < 0x11a1) {
            if (iVar1 == 0x1191) {
              return "SSLv3 write certificate verify B";
            }
          }
          else {
            if (iVar1 == 0x11a1) {
              return "SSLv3 write change cipher spec B";
            }
            if (iVar1 == 0x11b0) {
              return "SSLv3 write finished A";
            }
          }
        }
      }
      else {
        if (iVar1 == 0x11e0) {
          return "SSLv3 read server session ticket A";
        }
        if (iVar1 < 0x11e1) {
          if (iVar1 == 0x11c1) {
            return "SSLv3 read change cipher spec B";
          }
          if (iVar1 < 0x11c2) {
            if (iVar1 == 0x11c0) {
              return "SSLv3 read change cipher spec A";
            }
          }
          else {
            if (iVar1 == 0x11d0) {
              return "SSLv3 read finished A";
            }
            if (iVar1 == 0x11d1) {
              return "SSLv3 read finished B";
            }
          }
        }
        else {
          if (iVar1 == 0x1211) {
            return "SSLv2/v3 write client hello B";
          }
          if (iVar1 < 0x1212) {
            if (iVar1 == 0x11e1) {
              return "SSLv3 read server session ticket B";
            }
            if (iVar1 == 0x1210) {
              return "SSLv2/v3 write client hello A";
            }
          }
          else {
            if (iVar1 == 0x1220) {
              return "SSLv2/v3 read server hello A";
            }
            if (iVar1 == 0x1221) {
              return "SSLv2/v3 read server hello B";
            }
          }
        }
      }
    }
  }
  else {
    if (iVar1 == 0x2180) {
      return "SSLv3 read client certificate A";
    }
    if (iVar1 < 0x2181) {
      if (iVar1 == 0x2122) {
        return "SSLv3 write hello request C";
      }
      if (iVar1 < 0x2123) {
        if (iVar1 == 0x2112) {
          return "SSLv3 read client hello C";
        }
        if (iVar1 < 0x2113) {
          if (iVar1 == 0x2100) {
            return "SSLv3 flush data";
          }
          if (iVar1 < 0x2101) {
            if (iVar1 == 0x2003) {
              return "ok/accept SSL initialization";
            }
          }
          else {
            if (iVar1 == 0x2110) {
              return "SSLv3 read client hello A";
            }
            if (iVar1 == 0x2111) {
              return "SSLv3 read client hello B";
            }
          }
        }
        else {
          if (iVar1 == 0x2114) {
            return "DTLS1 write hello verify request B";
          }
          if (iVar1 < 0x2114) {
            return "DTLS1 write hello verify request A";
          }
          if (iVar1 == 0x2120) {
            return "SSLv3 write hello request A";
          }
          if (iVar1 == 0x2121) {
            return "SSLv3 write hello request B";
          }
        }
      }
      else {
        if (iVar1 == 0x2150) {
          return "SSLv3 write key exchange A";
        }
        if (iVar1 < 0x2151) {
          if (iVar1 == 0x2131) {
            return "SSLv3 write server hello B";
          }
          if (iVar1 < 0x2132) {
            if (iVar1 == 0x2130) {
              return "SSLv3 write server hello A";
            }
          }
          else {
            if (iVar1 == 0x2140) {
              return "SSLv3 write certificate A";
            }
            if (iVar1 == 0x2141) {
              return "SSLv3 write certificate B";
            }
          }
        }
        else {
          if (iVar1 == 0x2161) {
            return "SSLv3 write certificate request B";
          }
          if (iVar1 < 0x2162) {
            if (iVar1 == 0x2151) {
              return "SSLv3 write key exchange B";
            }
            if (iVar1 == 0x2160) {
              return "SSLv3 write certificate request A";
            }
          }
          else {
            if (iVar1 == 0x2170) {
              return "SSLv3 write server done A";
            }
            if (iVar1 == 0x2171) {
              return "SSLv3 write server done B";
            }
          }
        }
      }
    }
    else {
      if (iVar1 == 0x21d1) {
        return "SSLv3 write change cipher spec B";
      }
      if (iVar1 < 0x21d2) {
        if (iVar1 == 0x21a1) {
          return "SSLv3 read certificate verify B";
        }
        if (iVar1 < 0x21a2) {
          if (iVar1 == 0x2190) {
            return "SSLv3 read client key exchange A";
          }
          if (iVar1 < 0x2191) {
            if (iVar1 == 0x2181) {
              return "SSLv3 read client certificate B";
            }
          }
          else {
            if (iVar1 == 0x2191) {
              return "SSLv3 read client key exchange B";
            }
            if (iVar1 == 0x21a0) {
              return "SSLv3 read certificate verify A";
            }
          }
        }
        else {
          if (iVar1 == 0x21c0) {
            return "SSLv3 read finished A";
          }
          if (iVar1 < 0x21c1) {
            if (iVar1 == 0x21b0) {
              return "SSLv3 read change cipher spec A";
            }
            if (iVar1 == 0x21b1) {
              return "SSLv3 read change cipher spec B";
            }
          }
          else {
            if (iVar1 == 0x21c1) {
              return "SSLv3 read finished B";
            }
            if (iVar1 == 0x21d0) {
              return "SSLv3 write change cipher spec A";
            }
          }
        }
      }
      else {
        if (iVar1 == 0x2210) {
          return "SSLv2/v3 read client hello A";
        }
        if (iVar1 < 0x2211) {
          if (iVar1 == 0x21e1) {
            return "SSLv3 write finished B";
          }
          if (iVar1 < 0x21e2) {
            if (iVar1 == 0x21e0) {
              return "SSLv3 write finished A";
            }
          }
          else {
            if (iVar1 == 0x21f0) {
              return "SSLv3 write session ticket A";
            }
            if (iVar1 == 0x21f1) {
              return "SSLv3 write session ticket B";
            }
          }
        }
        else {
          if (iVar1 == 0x4000) {
            return "before SSL initialization";
          }
          if (iVar1 < 0x4001) {
            if (iVar1 == 0x2211) {
              return "SSLv2/v3 read client hello B";
            }
            if (iVar1 == 0x3004) {
              return "SSL renegotiate ciphers";
            }
          }
          else {
            if (iVar1 == 0x5000) {
              return "before/connect initialization";
            }
            if (iVar1 == 0x6000) {
              return "before/accept initialization";
            }
          }
        }
      }
    }
  }
  return "unknown state";
}

