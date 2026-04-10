# Portfolio Backend Setup

## Installation

1. Install dependencies:
```bash
npm install
```

2. Create `.env` file from template:
```bash
cp .env.example .env
```

3. Configure your email settings in `.env`:
   - For **Gmail**: Use an [App Password](https://support.google.com/accounts/answer/185833)
   - For other providers: Update `EMAIL_SERVICE` accordingly

## Running the Server

**Development** (with auto-reload):
```bash
npm run dev
```

**Production**:
```bash
npm start
```

Server will run on `http://localhost:5000` by default.

## Features

- ✅ Contact form submits to backend
- ✅ Automatic email to you with submission details
- ✅ Confirmation email sent to user
- ✅ CORS enabled for frontend requests
- ✅ Error handling and validation

## Email Setup (Gmail)

1. Enable 2-Factor Authentication on your Google Account
2. Generate an [App Password](https://myaccount.google.com/apppasswords)
3. Use the 16-character password in `.env` as `EMAIL_PASSWORD`
4. Set `EMAIL_USER` to your Gmail address

## API Endpoints

### POST `/api/contact`
Send a contact form submission.

**Body:**
```json
{
  "name": "John Doe",
  "email": "john@example.com",
  "subject": "Project Inquiry",
  "message": "I'd like to discuss..."
}
```

### GET `/api/health`
Check if server is running.
