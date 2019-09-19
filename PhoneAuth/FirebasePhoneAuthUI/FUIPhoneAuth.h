//
//  Copyright (c) 2016 Google Inc.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <FirebaseUI/FirebaseAuthUI.h>

NS_ASSUME_NONNULL_BEGIN

@class FUIPhoneAuth;

@protocol FUIPhoneAuthDelegate <NSObject>

@optional

/** @fn authUI:didSignInWithAuthDataResult:error:
 @brief Message sent after the sign in process has completed to report the signed in user or
 error encountered.
 @param authUI The @c FUIAuth instance sending the message.
 @param authDataResult The data result if the sign in attempt was successful.
 @param url pass the deep link associated with an email link sign-in completion. It is useful
 for the developer to access the state before the sign-in attempt was triggered.
 @param error The error that occurred during sign in, if any.
 */
- (void)authUI:(FUIAuth *)authUI
     phoneAuth:(FUIPhoneAuth *)phoneAuth
firebasePhoneLoginImpressionView:(UIViewController *)viewController;
- (void)authUI:(FUIAuth *)authUI
phoneAuth:(FUIPhoneAuth *)phoneAuth
firebasePhoneLoginStartWithPhoneNumber:(NSString *)phoneNumber
          view:(UIViewController *)viewController;

@end

/** @class FUIPhoneAuth
    @brief AuthUI components for Phone Sign In.
 */
@interface FUIPhoneAuth : NSObject <FUIAuthProvider>

@property(nonatomic, weak) id<FUIPhoneAuthDelegate> delegate;

/** @fn init
    @brief Please use @c initWithAuthUI: .
 */
- (instancetype)init NS_UNAVAILABLE;

/** @fn initWithAuthUI:
    @param authUI The @c FUIAuth instance that manages controllers of this provider.
 */
- (instancetype)initWithAuthUI:(FUIAuth *)authUI NS_DESIGNATED_INITIALIZER;

/** @fn initWithAuthUI:whitelistedCountries:
    @param authUI The @c FUIAuth instance that manages controllers of this provider.
    @param countries A set of whitelisted country codes. Country codes are in NSString format, and
           are either ISO (alpha-2) or E164 formatted.
 */
- (instancetype)initWithAuthUI:(FUIAuth *)authUI
          whitelistedCountries:(NSSet<NSString *> *)countries;

/** @fn initWithAuthUI:blacklistedCountries:
    @param authUI The @c FUIAuth instance that manages controllers of this provider.
    @param countries A set of blacklisted country codes. Country codes are in NSString format, and
           are either ISO (alpha-2) or E164 formatted.
 */
- (instancetype)initWithAuthUI:(FUIAuth *)authUI
          blacklistedCountries:(NSSet<NSString *> *)countries;

/** @fn signInWithPresentingViewController:
    @brief Signs in with phone auth provider.
        @see FUIAuthDelegate.authUI:didSignInWithAuthDataResult:URL:error: for method callback.
    @param presentingViewController The view controller used to present the UI.
 */
- (void)signInWithPresentingViewController:(UIViewController *)presentingViewController
__attribute__((deprecated("This is deprecated API and will be removed in a future release."
                          "Please use signInWithPresentingViewController:phoneNumber:")));

/** @fn signInWithPresentingViewController:phoneNumber:
    @brief Signs in with phone auth provider.
        @see FUIAuthDelegate.authUI:didSignInWithAuthDataResult:URL:error: for method callback.
    @param presentingViewController The view controller used to present the UI.
    @param phoneNumber The default phone number specified in the international format
        e.g. +14151112233
 */
- (void)signInWithPresentingViewController:(UIViewController *)presentingViewController
                               phoneNumber:(nullable NSString *)phoneNumber;

- (void)setDefaultContryCode:(NSString *)code;

@property (copy, nonatomic) NSString *phoneNumber;


@end

NS_ASSUME_NONNULL_END
